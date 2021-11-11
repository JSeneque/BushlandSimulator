#pragma once
#include "State.h"
#include <iostream>
#include "Graph.h"

class SearchFoodState : public State {
public:
    SearchFoodState(std::vector<Node>& nodeList, std::vector<int> foodMap, int _mapWidth);
    ~SearchFoodState() {};

    void onUpdate(Agent* agent, float deltaTime) override;

    void onEnter(Agent* agent);

    void onExit(Agent* agent)
    {
        std::cout << "Search food state exit\n";
    }

    void SetTileSize(int tileSize, int scale)
    {
        _width = tileSize * scale;
    }

private:
    std::vector<int> _mapData;
    std::vector<int> _foodTiles;
    std::vector<Node> _nodeList;
    bool _moving;
    int _width;
    int _mapWidth;
};