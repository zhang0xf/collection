#include "BT.h"
#include <random>
#include <functional>

using namespace BT;

int main() {
    // 构建行为树：
    // 角色一开始处于巡逻状态，一旦发现敌人，先检查自己生命值是否过低，如果是就逃跑，否则就攻击敌人；
    // 攻击过程中如果生命值过低也会中断攻击，立即逃跑，如果敌人死亡则立即停止攻击
    BT::BehaviorTreeBuilder *builder = new BT::BehaviorTreeBuilder();
    // 禁用代码自动格式化
    // clang-format off
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
    // clang-format on

    // 模拟执行行为树
    for (int i = 0; i < 10; ++i) {
        Bt->Tick();
        std::cout << std::endl;
    }

    Bt->Release();

    // system("pause");
    return 0;
}