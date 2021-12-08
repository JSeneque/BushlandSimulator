#pragma once
#include <vector>
#include "Graph.h"

enum HeuristicFn 
{
    DISTANCE,
    MANHATTAN_DISTANCE
};

class AStar {

public:
    AStar() {};
    ~AStar() {};

    std::vector<const Node*> AStarSearch(Node* startNode, Node* endNode);
    void MakeMap();

private:
    float Heuristic(const Node* current, const Node* end, HeuristicFn h = DISTANCE);
};