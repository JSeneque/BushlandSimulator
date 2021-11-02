#pragma once

#include "Condition.h"
#include "Agent.h"

class HungerCondition : public Condition
{
public:
    HungerCondition() {}
    ~HungerCondition() {}

    bool Test(Agent* agent) const override {
        return agent->GetHunger() < 5.0f;
    }
};