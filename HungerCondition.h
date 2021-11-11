#pragma once

#include "Condition.h"
#include "Agent.h"

class HungerCondition : public Condition
{
public:
    HungerCondition(float value) : _hungerLimit{value} {}
    ~HungerCondition() {}

    bool Test(Agent* agent) const override {
        return agent->GetHunger() < _hungerLimit;
    }

private:
    float _hungerLimit;
};