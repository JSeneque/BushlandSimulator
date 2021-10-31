#include "Grid.h"

// use division to check top and bottom
// use modulus to check left and right

Grid::Grid(int rows, int columns, int tileSize) :
    _map_x_dim{rows},
    _map_y_dim {columns},
    _tileSize {tileSize}
{


}

Grid::~Grid()
{

}

void Grid::MakeGrid(std::vector<Node>& nodeList, std::vector<int> mapData)
{
    nodeList.clear();
    nodeList.resize(_map_x_dim * _map_y_dim);

    for (int i = 0; i < nodeList.size(); i++)
    {
        nodeList[i].id = i;
    }
    

    for (int i = 0; i < nodeList.size(); i++)
    {
        //nodeList[i].id = i;

        auto assignWeight = [&](int id) {
            float weight = mapData[id] == 1 ? 1000000.0f : 1.0f;
            nodeList[i].outgoingEdges.push_back(Edge{&nodeList[id], weight});
        };

        // if can add to left
        if(i % _map_x_dim != 0)
            assignWeight(i - 1);
        
        // if can add to the right
        if((i + 1) % _map_x_dim != 0)
            assignWeight(i + 1);

        // if can add above
        if (i / _map_x_dim != _map_y_dim - 1)
            assignWeight(i + _map_x_dim);
        
        // if can add below
        if (i / _map_x_dim != 0)
            assignWeight(i - _map_x_dim);
    }
    
}

void Grid::DrawGrid()
{
    // draw verital lines
    for (int i = 0; i < _map_x_dim; i++)
    {
        DrawLine( i * _tileSize * 4, 0, i * _tileSize * 4, _map_y_dim * _tileSize * 4, WHITE);
    }

    // draw horizontal lines
    for (int i = 0; i < _map_y_dim; i++)
    {
        DrawLine( 0, i * _tileSize * 4, _map_x_dim * _tileSize * 4, i * _tileSize * 4, WHITE);
    }

    for (int i = 0; i < 100; i++)
    {
        int x = ( i % _map_x_dim) * _tileSize * 4 + _tileSize * 4 / 2;
        int y = ( i / _map_x_dim) * _tileSize * 4 + _tileSize * 4 / 2;
        DrawText(FormatText("%i", i), x, y, 24, WHITE );
    }
    
}

void Grid::DrawPath(std::list<const Node*> path)
{
    if(path.size() > 2)
    {
        for (auto i = path.begin(), j = std::next(path.begin()); j != path.end(); ++i, ++j)
        {
            int id = (*i)->id;
            int jd = (*j)->id;
            float ix = (id % _map_x_dim) * _tileSize * 4 + _tileSize * 4 / 2;
            float iy = (id / _map_x_dim) * _tileSize * 4 + _tileSize * 4 / 2;
            float jx = (jd % _map_x_dim) * _tileSize * 4 + _tileSize * 4 / 2;
            float jy = (jd / _map_x_dim) * _tileSize * 4 + _tileSize * 4 / 2;
            DrawLine(ix, iy, jx, jy, RED);
        }
    }
}

void Grid::MakeMap(std::vector<int>& mapData)
{
    // mapData.resize(_map_x_dim * _map_y_dim);

    // non-walkable areas
    /*mapData = {1,1,1,1,1,1,1,1,1,1,
                1,1,1,1,1,1,1,1,1,1,
                1,1,0,0,0,0,1,1,1,1,
                1,1,0,1,0,0,1,1,1,1,
                1,1,0,0,0,0,0,0,1,1,
                1,1,0,0,0,0,1,0,1,1,
                1,1,0,0,0,0,0,0,1,1,
                1,1,0,0,0,0,0,0,1,1,
                1,1,1,1,1,1,1,1,1,1,
                1,1,1,1,1,1,1,1,1,1};*/

}

void Grid::DrawMap(std::vector<int> mapData)
{
    for (int i = 0; i < mapData.size(); i++)
    {
        if (mapData[i] == 1)
        {
            int x = (( i % _map_x_dim) * _tileSize * 4); //+ //_tileSize * 4 / 2) ;
            int y = ( i / _map_x_dim) * _tileSize * 4; //+ _tileSize * 4 / 2;

            DrawRectangle(x, y, _tileSize * 4, _tileSize * 4, RED);
        }
    }
    
}