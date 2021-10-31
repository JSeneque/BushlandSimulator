#include <vector>
#include "Graph.h"

class Agent;

class Grid
{

public:
    Grid(int rows, int columns, int tileSize);
    ~Grid();

    void MakeGrid(std::vector<Node>& input, std::vector<int> mapData);
    void DrawGrid();
    void DrawPath(std::vector<const Node*>);
    void MakeMap(std::vector<int>& mapData);
    void DrawMap(std::vector<int> mapData);
    void MoveAgentAlongPath(std::list<const Node*> path, Agent* agent);

private:
    int _map_x_dim{0};
    int _map_y_dim{0};
    int _tileSize{0};

};