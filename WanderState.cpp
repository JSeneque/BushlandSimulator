#include "WanderState.h"
#include <iostream>
#include "Dijkstras.h"
#include "Agent.h"
#include <unordered_set>
#include <algorithm>
#include <cstdlib>

WanderState::WanderState(std::vector<Node>& nodeList, std::vector<int> obstacleMap)
{
    _mapData = obstacleMap;
    _nodeList = nodeList;

    // go through the map data and build a list of 
    // walkable times
    for (int i = 0; i < _mapData.size(); i++)
    {
        if(_mapData[i] == 0)
        {
            _walkableTiles.push_back(i);
        }
    }
} 

void WanderState::onUpdate(Agent* agent, float deltaTime)
{
    // have we set a target position to wander too
    // if not, get a random location
    // check if the agent's current position
    // if the agent is not at the target position
    //      Move agent towards position
    // else if at position
    //      Random another location
    // end
    int destination;

    if (!agent->IsMoving())
    {
        // get the current tile the bunny is in
        Vector2 bunnyPosition = agent->GetPosition();

        // World pos to index (i = x + width*y;)
        int index = int(bunnyPosition.x / _width) + (10 * int(bunnyPosition.y/_width));

        do
        {
            destination = _walkableTiles[rand() % _walkableTiles.size()];
        } while (index == destination);

        Dijkstras dijkstrasSearch;

        // create a path from the bunny's current position to the target
        auto path = dijkstrasSearch.DijkstrasSearch(&_nodeList[index], &_nodeList[destination]);
        
        agent->SetPath(path);
        agent->SetIsMoving(true);
    }

    
}

