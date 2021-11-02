#pragma once

class Agent;

class Condition  {
public:
    Condition() {}
    virtual ~Condition() {}

    virtual bool Test(Agent* agent) const = 0;
    virtual bool Update(Agent* agent, float time) {
        if (Test(agent))
            return true;

        return false;
    }
};