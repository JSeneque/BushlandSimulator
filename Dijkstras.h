#include <list>
#include "Graph.h"


class Dijkstras {

public:
    Dijkstras();
    ~Dijkstras();

    std::list<const Node*> DijkstrasSearch(Node* startNode, Node* endNode);
    void MakeMap();

    

};