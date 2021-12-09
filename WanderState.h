#pragma once
#include "State.h"
#include <iostream>
#include <vector>
#include "Graph.h"
#include "Agent.h"


class WanderState : public State {
public:
    WanderState(std::vector<Node>& nodeList, std::vector<int> obstacleMap);
    ~WanderState() {};

    void onUpdate(Agent* agent, float deltaTime) override;

    void onEnter(Agent* agent)
    {
        std::cout << "Wander state enter\n";
        std::cout << "Agent's Hunger: " << agent->GetHunger() << std::endl;
        agent->DrawStateText("Wander");
    }

    void onExit(Agent* agent)
    {
        std::cout << "Wander state exit\n";
    }

    void SetTileSize(int tileSize, int scale)
    {
        _width = tileSize * scale;
    }

private:
    std::vector<int> _mapData;
    std::vector<int> _walkableTiles;
    std::vector<Node> _nodeList;
    bool _moving;
    int _width;
};