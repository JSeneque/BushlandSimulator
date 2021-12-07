#include <vector>
#include "Graph.h"

class AStar {

public:
    AStar();
    ~AStar();

    std::vector<const Node*> AStarSearch(Node* startNode, Node* endNode);
    void MakeMap();

private:
    float Heuristic(const Node*, const Node*);
};