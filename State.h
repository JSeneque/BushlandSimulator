#pragma once

#include <vector>

class Agent;
class Transition;

class State
{
public :
    virtual ~State() {};
    virtual void onUpdate(Agent* agent, float deltaTime) = 0;
    virtual void onEnter(Agent* agent) {};
    virtual void onExit(Agent* agent) {};

    void AddTransition(Transition* transition)
    {
        _transitions.push_back(transition);
    }

    Transition* GetTriggeredTransition(Agent* agent);

protected:
    std::vector<Transition*> _transitions;

};