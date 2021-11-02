#pragma once
#include "State.h"
#include <iostream>
#include <vector>
#include "Graph.h"


class DeadState : public State {
public:
    DeadState() {};
    ~DeadState() {};

    void onUpdate(Agent* agent, float deltaTime) override {};

    void onEnter(Agent* agent)
    {
        std::cout << "Dead state enter\n";
    }

    void onExit(Agent* agent)
    {
        std::cout << "Dead state exit\n";
    }


};