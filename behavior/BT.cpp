#include <assert.h>
#include "BT.h"

using namespace BT;

void BehaviorTree::Tick() {
    Root->Tick();
}

BehaviorTreeBuilder *BehaviorTreeBuilder::Sequence() {
    Behavior *Sq = Sequence::Create();
    AddBehavior(Sq);
    return this;
}

BehaviorTreeBuilder *BehaviorTreeBuilder::Action(EActionMode ActionModes) {
    Behavior *Ac;
    switch (ActionModes) {
    case EActionMode::ATTACK:
        Ac = Action_Attack::Create();
        break;

    case EActionMode::PATROL:
        Ac = Action_Patrol::Create();
        break;

    case EActionMode::RUNAWAY:
        Ac = Action_Runaway::Create();
        break;

    default:
        Ac = nullptr;
        break;
    }

    AddBehavior(Ac);

    return this;
}

BehaviorTreeBuilder *BehaviorTreeBuilder::Condition(EConditionMode ConditionMode, bool IsNegation) {
    Behavior *Cd;
    switch (ConditionMode) {
    case EConditionMode::IS_SEE_ENEMY:
        Cd = Condition_IsSeeEnemy::Create(IsNegation);
        break;

    case EConditionMode::IS_HEALTH_LOW:
        Cd = Condition_IsHealthLow::Create(IsNegation);
        break;

    case EConditionMode::IS_ENEMY_DEAD:
        Cd = Condition_IsEnemyDead::Create(IsNegation);
        break;

    default:
        Cd = nullptr;
        break;
    }

    AddBehavior(Cd);

    return this;
}

BehaviorTreeBuilder *BehaviorTreeBuilder::Selector() {
    Behavior *St = Selector::Create();

    AddBehavior(St);

    return this;
}

BehaviorTreeBuilder *BehaviorTreeBuilder::Repeat(int RepeatNum) {
    Behavior *Rp = Repeat::Create(RepeatNum);

    AddBehavior(Rp);

    return this;
}

BehaviorTreeBuilder *BehaviorTreeBuilder::ActiveSelector() {
    Behavior *Ast = ActiveSelector::Create();

    AddBehavior(Ast);

    return this;
}

BehaviorTreeBuilder *BehaviorTreeBuilder::Fliter() {
    Behavior *Ft = Fliter::Create();

    AddBehavior(Ft);

    return this;
}

BehaviorTreeBuilder *BehaviorTreeBuilder::Parallel(Poly InSucess, Poly InFailure) {
    Behavior *Pl = Parallel::Create(InSucess, InFailure);

    AddBehavior(Pl);

    return this;
}
BehaviorTreeBuilder *BehaviorTreeBuilder::Monitor(Poly InSucess, Poly InFailure) {
    Behavior *Mt = Monitor::Create(InSucess, InFailure);

    AddBehavior(Mt);

    return this;
}

BehaviorTreeBuilder *BehaviorTreeBuilder::Back() {
    NodeStack.pop();
    return this;
}

BehaviorTree *BehaviorTreeBuilder::End() {
    while (!NodeStack.empty()) {
        NodeStack.pop();
    }
    BehaviorTree *Tmp = new BehaviorTree(TreeRoot);
    TreeRoot = nullptr;
    return Tmp;
}

void BehaviorTreeBuilder::AddBehavior(Behavior *NewBehavior) {
    assert(NewBehavior);

    if (!TreeRoot) {
        TreeRoot = NewBehavior;
    } else {
        NodeStack.top()->AddChild(NewBehavior);
    }

    NodeStack.push(NewBehavior);
}