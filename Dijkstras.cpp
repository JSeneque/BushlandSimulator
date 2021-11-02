#include "Dijkstras.h"
#include <stdexcept>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <iostream>

Dijkstras::Dijkstras() 
{

}

Dijkstras::~Dijkstras()
{

}

std::vector<const Node*> Dijkstras::DijkstrasSearch(Node* startNode, Node* endNode)
{
    if (!startNode->id || !endNode->id)
    {
        throw std::runtime_error("Null nodes passed in!");
    }

    if (startNode->id == endNode->id)
    {
        return std::vector<const Node*>();
    }

    // set the running cost on the start node to zero
    startNode->runningCost = 0;
    // the start node does not have a parent
    startNode->parentNode = nullptr;

    // create an open and close list for storing the nodes we have visited
    std::vector<Node*> openList;
    std::unordered_set<const Node*> closeList;

    // add start node to the open list
    openList.push_back(startNode);

    // while the open list is not empty
    while(!openList.empty())
    {
        // compare the nodes weight
        auto sortNodes =[](const Node* a, const Node* b) {
            return a->runningCost < b->runningCost;
        };

        // sorting the list
        std::sort(openList.begin(), openList.end(), sortNodes);

        // get the first node in the list
        Node* currentNode = openList.front();

        // check if the current node is the end node
        if(currentNode->id == endNode->id)
        {
            endNode = currentNode;
            break;
        }

        // remove the currentNode from the open list
        openList.erase(openList.begin());
        // add the current node to the close list
        closeList.insert(currentNode);

        // add any connection nodes not in the close list to the open list
        for (auto& edge : currentNode->outgoingEdges)
        {
            // search the edge destination node is not already in the close list
            if( std::find(closeList.begin(), closeList.end(), edge.destination) == closeList.end()) 
            {
                // calculate the score
                float runningCost = currentNode->runningCost + edge.weight;

                // search the edge destination node is not already in the open list
                if( std::find(openList.begin(), openList.end(), edge.destination) == openList.end()) 
                {
                    edge.destination->runningCost = runningCost;
                    edge.destination->parentNode = currentNode;
                    openList.push_back(edge.destination);
                }
                // if the node is already in the open list and the running cost is lower
                else if (runningCost < edge.destination->runningCost)
                {
                    edge.destination->runningCost = runningCost;
                    edge.destination->parentNode = currentNode;
                }
            }
        }
    }

    std::vector<const Node*> path;
    Node* currentNode = endNode;
    if (!endNode->parentNode)
    {
        return path;
    }

    while (currentNode)
    {
        //path.push_front(currentNode);
        path.insert(path.begin(), currentNode);
        currentNode = currentNode->parentNode;
    }
    return path;
}

