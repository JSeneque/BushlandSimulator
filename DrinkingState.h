#pragma once
#include "State.h"
#include <iostream>
#include <vector>
#include "Graph.h"


class DrinkingState : public State {
public:
    DrinkingState() {};
    ~DrinkingState() {};

    void onUpdate(Agent* agent, float deltaTime) override {};

    void onEnter(Agent* agent)
    {
        std::cout << "Drinking State enter\n";
    }

    void onExit(Agent* agent)
    {
        std::cout << "Drinking State exit\n";
    }
};