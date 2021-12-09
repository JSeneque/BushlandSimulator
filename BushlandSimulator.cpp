#include "raylib.h"
#include "Agent.h"
#include "Dijkstras.h"
#include "Graph.h"
#include <vector>
#include <iostream>
#include "Grid.h"
#include "FiniteStateMachine.h"
#include "WanderState.h"
#include "SearchFoodState.h"
#include "HungerCondition.h"
#include "Transition.h"
#include "DeadState.h"
#include "EatingState.h"
#include "DeathCondition.h"
#include "EatingCondition.h"
#include "ReplenishedCondition.h"

int main()
{
    const int windowWidth{640};
    const int windowHeight{640};
    const int mapWidth = 10;
    const int mapHeight = 10;
    const int tileSize = 16;
    
    std::vector<Node> nodeList;
    std::cout << "nodeList address: " << &nodeList << std::endl;
    Grid* grid = new Grid(mapWidth, mapHeight, tileSize);

    std::vector<int> mapData = {
                1,1,1,1,1,1,1,1,1,1,
                1,1,1,1,1,1,1,1,1,1,
                1,1,0,0,0,2,1,1,1,1,
                1,1,0,1,0,0,1,1,1,1,
                1,1,0,0,0,0,0,0,1,1,
                1,1,2,0,0,0,1,0,1,1,
                1,1,0,0,0,0,0,0,1,1,
                1,1,0,0,0,0,0,0,1,1,
                1,1,1,1,1,1,1,1,1,1,
                1,1,1,1,1,1,1,1,1,1};

    grid->MakeGrid(nodeList, mapData);
    std::cout << "nodeList address: " << &nodeList << std::endl;

    InitWindow(windowWidth, windowHeight, "BushlandSimulator");

    Texture2D map = LoadTexture("tileset/world_map.png");
    
    // setup states
    auto wanderState = new WanderState(nodeList, mapData);
    wanderState->SetTileSize(tileSize, 4);
    auto searchForFoodState = new SearchFoodState(nodeList, mapData, mapWidth);
    searchForFoodState->SetTileSize(tileSize, 4);
    auto deathState = new DeadState();
    auto eatingState = new EatingState();

    // setup conditions
    auto hungerCondition = new HungerCondition(10.0f);
    auto deathCondition = new DeathCondition();
    auto eatingCondition = new EatingCondition();
    auto replendishedCondition = new ReplendishedCondition();

    // setup transitions
    auto toSearchFoodTransition = new Transition(searchForFoodState, hungerCondition);
    auto toDeathTransition = new Transition(deathState, deathCondition);
    auto toEatingTransition = new Transition(eatingState, eatingCondition);
    auto toWanderTransition = new Transition(wanderState, replendishedCondition);

    wanderState->AddTransition(toSearchFoodTransition);
    searchForFoodState->AddTransition(toDeathTransition);
    searchForFoodState->AddTransition(toEatingTransition);
    eatingState->AddTransition(toWanderTransition);

    FiniteStateMachine bunnyBehaviour;
    bunnyBehaviour.AddState(wanderState);
    bunnyBehaviour.AddState(searchForFoodState);
    bunnyBehaviour.AddState(deathState);
    bunnyBehaviour.AddState(eatingState);
    bunnyBehaviour.SetCurrentState(wanderState);

    std::vector<Agent*> bunnies;

    for (int i = 0; i < 1; i++)
    {
        Agent* bunny = new Agent(Vector2{320,320}, "animals/bunny/bunny_animations.png", 21, 21, 4, 6);
        bunny->SetMapWidth(mapWidth);
        bunny->SetMapHeight(mapHeight);
        bunny->SetTileSize(tileSize);
        bunnies.push_back(bunny);
    }
     

    SetTargetFPS(60);

    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        Vector2 mapPos {0,0};
        // draw map
        DrawTextureEx(map, mapPos, 0.0, 4.0, WHITE);
        
        
        //bunny->FollowPath(mapWidth, tileSize, path);
        // highlight obstacles
        if(IsKeyDown(KEY_SPACE))
        {   
             grid->DrawGrid();
             grid->DrawMap(mapData);
             
             // draw nodes processed by A star algorithm
             //grid->DrawProcessedNode(nodeList);
        }
        
        // draw bunny
        for(auto bunny : bunnies)
        {
            bunnyBehaviour.Update(bunny, GetFrameTime());
            bunny->Update(GetFrameTime());
            bunny->Draw();
            if(IsKeyDown(KEY_SPACE)) {
                grid->DrawPath(bunny->GetPath());
                bunny->DrawUI();
            }
        }
        
        EndDrawing();
    }

    UnloadTexture(map); 
       
    CloseWindow();  
}




