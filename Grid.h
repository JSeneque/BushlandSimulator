#include <vector>
#include "Graph.h"

class Grid
{

public:
    Grid(int rows, int columns, int tileSize);
    ~Grid();

    void MakeGrid(std::vector<Node>& input);
    void DrawGrid();
    void DrawPath(std::list<const Node*>);
    void MakeMap(std::vector<int>& mapData);
    void DrawMap(std::vector<int> mapData);

private:
    int _map_x_dim{0};
    int _map_y_dim{0};
    int _tileSize{0};

};