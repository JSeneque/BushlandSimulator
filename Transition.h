#pragma once

#include "Condition.h"

class State;
class Agent;

class Transition {
public:
    Transition(State* target, Condition* condition) : 
        _target(target),
        _condition (condition)
        { }
    ~Transition() {}

    State* GetTargetState() { return _target; }
    bool HasTriggered(Agent* agent) { return _condition->Test(agent); }

private:
    State* _target;
    Condition* _condition;
};