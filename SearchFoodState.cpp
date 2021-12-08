#include "SearchFoodState.h"
//#include "Dijkstras.h"
#include <cstdlib>
#include "Agent.h"
#include "raymath.h"
#include "AStar.h"

SearchFoodState::SearchFoodState(std::vector<Node>& nodeList, std::vector<int> foodMap,int mapWidth)
{
    _mapData = foodMap;
    _nodeList = nodeList;
    _mapWidth = mapWidth;

    for (int i = 0; i < _mapData.size(); i++)
    {
        if(_mapData[i] == 2)
        {
            _foodTiles.push_back(i);
        }
    }
}

void SearchFoodState::onEnter(Agent* agent)
{
    std::cout << "Search food state enter\n";
    agent->SetIsMoving(false);
    agent->SetHasArrived(false);
}

void SearchFoodState::onUpdate(Agent* agent, float deltaTime)
{
    // std::cout << "Search food state update\n";
    int destination;
    if (_foodTiles.size() > 0)
    {
        if (!agent->GetHasArrived() && !agent->IsMoving())
        {
            // get the current tile the bunny is in
            Vector2 bunnyPosition = agent->GetPosition();

            // World pos to index (i = x + width*y;)
            int index = int(bunnyPosition.x / _width) + (10 * int(bunnyPosition.y/_width));
            
            int distance = 999999;
            // find the closest food source
            for(auto tile : _foodTiles)
            {
                // get food source position
                Vector2 _tilePos;
                _tilePos.x = (tile % _mapWidth) * _width;
                _tilePos.y = (tile / _mapWidth) * _width;

                // calculate the distance from bunny to food source and if the source is 
                // closer, we want that one
                if (distance > Vector2Distance(bunnyPosition, _tilePos))
                {
                    distance = Vector2Distance(bunnyPosition, _tilePos);
                    destination = tile;
                }
            }

            //Dijkstras dijkstrasSearch;
            AStar aStarSearch;

            // create a path from the bunny's current position to the target
            //auto path = dijkstrasSearch.DijkstrasSearch(&_nodeList[index], &_nodeList[destination]);
            auto path = aStarSearch.AStarSearch(&_nodeList[index], &_nodeList[destination]);
            
            agent->SetPath(path);
            agent->SetIsMoving(true);
        } 
    }
}