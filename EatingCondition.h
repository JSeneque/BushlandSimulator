#pragma once

#include "Condition.h"
#include "Agent.h"
#include <iostream>

class EatingCondition : public Condition
{
public:
    EatingCondition() {}
    ~EatingCondition() {}

    bool Test(Agent* agent) const override {
            return agent->GetPath().size() == agent->GetPathIndex() + 1;
            //return true;
    }
};