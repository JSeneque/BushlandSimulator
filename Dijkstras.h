#include <vector>
#include "Graph.h"


class Dijkstras {

public:
    Dijkstras();
    ~Dijkstras();

    std::vector<const Node*> DijkstrasSearch(Node* startNode, Node* endNode);
    void MakeMap();

    

};