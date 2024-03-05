﻿#pragma once
#include <stack>
#include "behavior.h"

namespace BT {
enum class EActionMode {
    ATTACK,
    PATROL,
    RUNAWAY,
};

enum class EConditionMode {
    IS_SEE_ENEMY,
    IS_HEALTH_LOW,
    IS_ENEMY_DEAD,
};

class BehaviorTree {
public:
    BehaviorTree(Behavior *InRoot) :
        Root(InRoot) {
    }
    void Tick();
    bool HaveRoot() {
        return Root ? true : false;
    }
    void SetRoot(Behavior *InNode) {
        Root = InNode;
    }
    void Release() {
        Root->Release();
    }

private:
    Behavior *Root;
};

// 行为树构建器，用来构建一棵行为树,通过前序遍历方式配合Back()和End()方法进行构建
class BehaviorTreeBuilder {
public:
    BehaviorTreeBuilder() {
    }
    ~BehaviorTreeBuilder() {
    }
    BehaviorTreeBuilder *Sequence();
    BehaviorTreeBuilder *Action(EActionMode ActionModes);
    BehaviorTreeBuilder *Condition(EConditionMode ConditionMode, bool IsNegation);
    BehaviorTreeBuilder *Selector();
    BehaviorTreeBuilder *Repeat(int RepeatNum);
    BehaviorTreeBuilder *ActiveSelector();
    BehaviorTreeBuilder *Fliter();
    BehaviorTreeBuilder *Parallel(Poly InSucess, Poly InFailure);
    BehaviorTreeBuilder *Monitor(Poly InSucess, Poly InFailure);
    BehaviorTreeBuilder *Back();
    BehaviorTree *End();

private:
    void AddBehavior(Behavior *NewBehavior);

private:
    Behavior *TreeRoot = nullptr;
    std::stack<Behavior *> NodeStack;
};
} // namespace BT
