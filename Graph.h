#pragma once
#include <list>
#include "raylib.h"
#include <limits>

struct Edge {
    struct Node* destination = nullptr;
    float weight = 1.0f;
};

struct Node {
    // ID
    unsigned int id{0};
    
    // Node data
    Vector2 position {};

    // graphy structure
    std::list<Edge> outgoingEdges;

    // pathfinding
    float runningCost = std::numeric_limits<float>::max();
    Node* parentNode = nullptr;
};