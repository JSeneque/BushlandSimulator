#pragma once

#include "Condition.h"
#include "Agent.h"
#include <iostream>

class ReplendishedCondition : public Condition
{
public:
    ReplendishedCondition() {}
    ~ReplendishedCondition() {}

    bool Test(Agent* agent) const override {
            return true;
    }
};