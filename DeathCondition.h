#pragma once

#include "Condition.h"
#include "Agent.h"

class DeathCondition : public Condition
{
public:
    DeathCondition() {}
    ~DeathCondition() {}

    bool Test(Agent* agent) const override {
        return agent->GetHunger() < 0.0f;
    }
};