#include <algorithm>
#include <random>
#include <functional>
#include "behavior.h"

using namespace BT;

// 随机1~100
std::random_device rd;
std::default_random_engine engine(rd());
std::uniform_int_distribution<> dis(1, 100);
auto dice = std::bind(dis, engine);

// 行为节点的更新操作
BStatus Behavior::Tick() {
    if (status != BStatus::RUNNING) {
        OnInitialize();
    }

    // 每次Tick()执行一次Update()
    status = Update();

    if (status != BStatus::RUNNING) {
        OnTerminate();
    }

    return status;
}

// 重复执行该节点
BStatus Repeat::Update() {
    while (true) {
        child->Tick();
        if (child->IsRunning()) return BStatus::SUCCESS;
        if (child->IsFailure()) return BStatus::FAILURE;
        if (++count == limited) return BStatus::SUCCESS;
        child->Reset();
    }
}

void Composite::Release() {
    for (auto it : childs) {
        it->Release();
    }
    delete this;
}

void Composite::RemoveChild(Behavior *child) {
    auto it = find(childs.begin(), childs.end(), child);
    if (it != childs.end()) {
        childs.erase(it);
    }
}

// 顺序更新复合节点
BStatus Sequence::Update() {
    while (true) {
        BStatus state = (*iter)->Tick();

        // 遇到一个不是成功的便返回
        if (state != BStatus::SUCCESS)
            return state;

        if (++iter == childs.end()) {
            return BStatus::SUCCESS;
        }
    }
}

// 选择更新复合节点
BStatus Selector::Update() {
    while (true) {
        BStatus state = (*iter)->Tick();

        // 遇到一个成功的便返回
        if (state == BStatus::SUCCESS)
            return state;

        if (++iter == childs.end()) {
            return BStatus::FAILURE;
        }
    }
}

// 并行更新复合节点
BStatus Parallel::Update() {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
    int successCount = 0;
#pragma GCC diagnostic pop
    int failureCount = 0;
    int count = childs.size();

    for (auto it : childs) {
        if (it->IsTerminate()) { continue; }

        it->Tick();

        if (it->IsSuccess()) {
            ++successCount;
            if (success == Poly::REQUIRE_ONE) {
                it->Reset();
                return BStatus::SUCCESS;
            }
        }

        if (it->IsFailure()) {
            ++failureCount;
            if (failure == Poly::REQUIRE_ONE) {
                it->Reset();
                return BStatus::FAILURE;
            }
        }
    }

    if (failure == Poly::REQUIRE_ALL && failureCount == count) {
        for (auto it : childs) {
            it->Reset();
        }

        return BStatus::FAILURE;
    }

    if (success == Poly::REQUIRE_ALL && failureCount == count) {
        for (auto it : childs) {
            it->Reset();
        }
        return BStatus::SUCCESS;
    }

    return BStatus::RUNNING;
}

void Parallel::OnTerminate() {
    for (auto it : childs) {
        if (it->IsRunning()) {
            it->Abort();
        }
    }
}

// 主动选择执行优先级高的节点
BStatus ActiveSelector::Update() {
    // 每次执行前,保存当前节点
    vector<Behavior *>::iterator currIter = iter;
    Selector::OnInitialize(); // 选择器每次重新选择节点
    BStatus state = Selector::Update();
    // 如果优先级更高的节点执行成功,则终端当前节点的执行
    if (currIter != childs.end() && currIter != iter) {
        (*currIter)->Abort();
    }
    return state;
}

// 随机数大于50，视为看见敌人
BStatus Condition_IsSeeEnemy::Update() {
    if (dice() > 50) {
        std::cout << "See enemy!" << std::endl;
        return !negation ? BStatus::SUCCESS : BStatus::FAILURE;
    } else {
        std::cout << "Not see enemy" << std::endl;
        return !negation ? BStatus::FAILURE : BStatus::SUCCESS;
    }
}

BStatus Condition_IsHealthLow::Update() {
    if (dice() > 80) {
        std::cout << "Health is low!" << std::endl;
        return !negation ? BStatus::SUCCESS : BStatus::FAILURE;
    } else {
        std::cout << "Health is not low" << std::endl;
        return !negation ? BStatus::FAILURE : BStatus::SUCCESS;
    }
}

BStatus Condition_IsEnemyDead::Update() {
    if (dice() > 50) {
        std::cout << "Enemy is Dead" << std::endl;
        return !negation ? BStatus::SUCCESS : BStatus::FAILURE;
    } else {
        std::cout << "Enemy is not Dead" << std::endl;
        return !negation ? BStatus::FAILURE : BStatus::SUCCESS;
    }
}

BStatus Action_Attack::Update() {
    std::cout << "Action_Attack " << std::endl;
    return BStatus::SUCCESS;
}

BStatus Action_Runaway::Update() {
    std::cout << "Action_Runaway" << std::endl;
    return BStatus::SUCCESS;
}

BStatus Action_Patrol::Update() {
    std::cout << "Action_Patrol" << std::endl;
    return BStatus::SUCCESS;
}