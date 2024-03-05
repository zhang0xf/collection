#pragma once
#include <string>
#include <vector>
#include <iostream>

using namespace std;

namespace BT {
// 行为树节点的状态
enum class BStatus {
    INVALID, // 初始/非法
    SUCCESS, // 成功
    FAILURE, // 失败
    RUNNING, // 运行
    ABORTED, // 终止
};

// 对于有多个行为的行为树节点的判定策略
enum class Poly {
    REQUIRE_ONE, // 一个行为执行成功，节点即返回成功。
    REQUIRE_ALL, // 所有行为全部执行成功，节点才返回成功。
};

class Behavior {
public:
    virtual void Release() = 0;

    BStatus Tick();

    void SetStatus(BStatus status) {
        this->status = status;
    }
    BStatus GetStatus() {
        return this->status;
    }

    void Reset() {
        status = BStatus::INVALID;
    }
    void Abort() {
        OnTerminate();
        status = BStatus::ABORTED;
    }

    bool IsTerminate() {
        return status == BStatus::FAILURE || status == BStatus::SUCCESS;
    }
    bool IsRunning() {
        return status == BStatus::RUNNING;
    }
    bool IsSuccess() {
        return status == BStatus::SUCCESS;
    }
    bool IsFailure() {
        return status == BStatus::FAILURE;
    }

    virtual string Name() = 0;

    virtual void AddChild(Behavior *child) {
        this->child = child;
    }

protected:
    Behavior() :
        status(BStatus::INVALID), child(nullptr) {
    }
    virtual ~Behavior() {
    }
    virtual void OnInitialize() {
    }
    virtual void OnTerminate() {
    }
    virtual BStatus Update() = 0;

protected:
    BStatus status;
    Behavior *child;
};

// 重复
class Repeat : public Behavior {
public:
    static Behavior *Create(int limited) {
        return new Repeat(limited);
    }
    virtual void Release() {
        child->Release();
        delete this;
    }
    virtual string Name() {
        return "Repeat";
    }

protected:
    Repeat(int limited) :
        limited(limited) {
    }
    virtual ~Repeat() {
    }
    virtual void OnInitialize() {
        count = 0;
    }
    virtual BStatus Update();

protected:
    int limited = 3;
    int count = 0;
};

// 复合节点
class Composite : public Behavior {
public:
    virtual void Release();
    virtual void AddChild(Behavior *child) {
        childs.push_back(child);
    }
    virtual void RemoveChild(Behavior *child);
    virtual void ClearChild() {
        childs.clear();
    }

protected:
    Composite() {
    }
    virtual ~Composite() {
    }

protected:
    vector<Behavior *> childs;
    vector<Behavior *>::iterator iter;
};

// 顺序
class Sequence : public Composite {
public:
    static Behavior *Create() {
        return new Sequence();
    }
    virtual string Name() {
        return "Sequence";
    }

protected:
    Sequence() {
    }
    virtual ~Sequence() {
    }
    virtual void OnInitialize() {
        iter = childs.begin();
    }
    virtual BStatus Update();
};

// 条件
class Condition : public Behavior {
public:
    virtual void Release() {
        delete this;
    }

protected:
    Condition(bool negation) :
        negation(negation) {
    }
    virtual ~Condition() {
    }

protected:
    bool negation = false;
};

// 动作
class Action : public Behavior {
public:
    virtual void Release() {
        delete this;
    }

protected:
    Action() {
    }
    virtual ~Action() {
    }
};

// 过滤
class Fliter : public Sequence {
public:
    static Behavior *Create() {
        return new Fliter();
    }
    void AddCondition(Condition *condition) {
        childs.insert(childs.begin(), condition);
    }
    void AddAction(Action *action) {
        childs.push_back(action);
    }
    virtual string Name() {
        return "Fliter";
    }

protected:
    Fliter() {
    }
    virtual ~Fliter() {
    }
};

// 选择
class Selector : public Composite {
public:
    static Behavior *Create() {
        return new Selector();
    }
    virtual string Name() {
        return "Selector";
    }

protected:
    Selector() {
    }
    virtual ~Selector() {
    }
    virtual void OnInitialize() {
        iter = childs.begin();
    }
    virtual BStatus Update();
};

// 并行
class Parallel : public Composite {
public:
    static Behavior *Create(Poly success, Poly failure) {
        return new Parallel(success, failure);
    }
    virtual string Name() {
        return "Parallel";
    }

protected:
    Parallel(Poly success, Poly failure) :
        success(success), failure(failure) {
    }
    virtual ~Parallel() {
    }
    virtual void OnTerminate();
    virtual BStatus Update();

protected:
    Poly success;
    Poly failure;
};

// 监视
class Monitor : public Parallel {
public:
    static Behavior *Create(Poly success, Poly failure) {
        return new Monitor(success, failure);
    }
    void AddCondition(Behavior *Condition) {
        childs.insert(childs.begin(), Condition);
    }
    void AddAction(Behavior *Action) {
        childs.push_back(Action);
    }
    virtual string Name() {
        return "Monitor";
    }

protected:
    Monitor(Poly success, Poly failure) :
        Parallel(success, failure) {
    }
    virtual ~Monitor() {
    }
};

// 主动选择
class ActiveSelector : public Selector {
public:
    static Behavior *Create() {
        return new ActiveSelector();
    }
    virtual string Name() {
        return "ActiveSelector";
    }

protected:
    ActiveSelector() {
    }
    virtual ~ActiveSelector() {
    }
    virtual void OnInitialize() {
        iter = childs.end();
    }
    virtual BStatus Update();
};

// 是否看见敌人
class Condition_IsSeeEnemy : public Condition {
public:
    static Behavior *Create(bool negation) {
        return new Condition_IsSeeEnemy(negation);
    }
    virtual string Name() {
        return "Condtion_IsSeeEnemy";
    }

protected:
    Condition_IsSeeEnemy(bool negation) :
        Condition(negation) {
    }
    virtual ~Condition_IsSeeEnemy() {
    }
    virtual BStatus Update();
};

// 是否血量低
class Condition_IsHealthLow : public Condition {
public:
    static Behavior *Create(bool negation) {
        return new Condition_IsHealthLow(negation);
    }
    virtual string Name() {
        return "Condition_IsHealthLow";
    }

protected:
    Condition_IsHealthLow(bool negation) :
        Condition(negation) {
    }
    virtual ~Condition_IsHealthLow() {
    }
    virtual BStatus Update();
};

// 是否敌人死亡
class Condition_IsEnemyDead : public Condition {
public:
    static Behavior *Create(bool negation) {
        return new Condition_IsEnemyDead(negation);
    }
    virtual string Name() {
        return "Condition_IsHealthLow";
    }

protected:
    Condition_IsEnemyDead(bool negation) :
        Condition(negation) {
    }
    virtual ~Condition_IsEnemyDead() {
    }
    virtual BStatus Update();
};

// 攻击动作
class Action_Attack : public Action {
public:
    static Behavior *Create() {
        return new Action_Attack();
    }
    virtual string Name() {
        return "Action_Attack";
    }

protected:
    Action_Attack() {
    }
    virtual ~Action_Attack() {
    }
    virtual BStatus Update();
};

// 逃跑动作
class Action_Runaway : public Action {
public:
    static Behavior *Create() {
        return new Action_Runaway();
    }
    virtual string Name() {
        return "Action_Runaway";
    }

protected:
    Action_Runaway() {
    }
    virtual ~Action_Runaway() {
    }
    virtual BStatus Update();
};

// 巡逻动作
class Action_Patrol : public Action {
public:
    static Behavior *Create() {
        return new Action_Patrol();
    }
    virtual string Name() {
        return "Action_Patrol";
    }

protected:
    Action_Patrol() {
    }
    virtual ~Action_Patrol() {
    }
    virtual BStatus Update();
};
} // namespace BT
