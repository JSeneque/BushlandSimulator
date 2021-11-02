#pragma once
#include "State.h"
#include <iostream>

class SearchFoodState : public State {
public:
    SearchFoodState() {};
    ~SearchFoodState() {};

    void onUpdate(Agent* agent, float deltaTime) override {};

    void onEnter(Agent* agent)
    {
        std::cout << "Search food state enter\n";
    }

    void onExit(Agent* agent)
    {
        std::cout << "Search food state exit\n";
    }


};