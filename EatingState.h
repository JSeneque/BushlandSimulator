#pragma once
#include "State.h"
#include <iostream>
#include <vector>
#include "Graph.h"


class EatingState : public State {
public:
    EatingState() {};
    ~EatingState() {};

    void onUpdate(Agent* agent, float deltaTime) override;

    void onEnter(Agent* agent)
    {
        std::cout << "Eating state enter\n";
    }

    void onExit(Agent* agent)
    {
        std::cout << "Eating state exit\n";
    }
};