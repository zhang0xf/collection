#include "BT.h"
#include <random>
#include <functional>

using namespace BT;

int main() {
    BT::BehaviorTreeBuilder *builder = new BT::BehaviorTreeBuilder();

    BT::BehaviorTree *Bt = builder
                               ->ActiveSelector()
                               ->Sequence()
                               ->Condition(BT::EConditionMode::IS_SEE_ENEMY, false)
                               ->Back()
                               ->ActiveSelector()
                               ->Sequence()
                               ->Condition(BT::EConditionMode::IS_HEALTH_LOW, false)
                               ->Back()
                               ->Action(BT::EActionMode::RUNAWAY)
                               ->Back()
                               ->Back()
                               ->Parallel(BT::Poly::REQUIRE_ALL, BT::Poly::REQUIRE_ONE)
                               ->Condition(BT::EConditionMode::IS_ENEMY_DEAD, true)
                               ->Back()
                               ->Action(BT::EActionMode::ATTACK)
                               ->Back()
                               ->Back()
                               ->Back()
                               ->Back()
                               ->Action(BT::EActionMode::PATROL)
                               ->End();
    delete builder;

    // 模拟执行行为树
    for (int i = 0; i < 10; ++i) {
        // 与游戏的一帧相关
        Bt->Tick();
        std::cout << std::endl;
    }

    Bt->Release();

    // system("pause");
    return 0;
}