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
#include "DeathCondition.h"

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
                1,1,0,0,0,0,1,1,1,1,
                1,1,0,1,0,0,1,1,1,1,
                1,1,0,0,0,0,0,0,1,1,
                1,1,0,0,0,0,1,0,1,1,
                1,1,0,0,0,0,0,0,1,1,
                1,1,0,0,0,0,0,0,1,1,
                1,1,1,1,1,1,1,1,1,1,
                1,1,1,1,1,1,1,1,1,1};

    grid->MakeGrid(nodeList, mapData);
    std::cout << "nodeList address: " << &nodeList << std::endl;

    InitWindow(windowWidth, windowHeight, "BushlandSimulator");

    Texture2D map = LoadTexture("tileset/world_map.png");
    
    Agent* bunny = new Agent(Vector2{320,320}, "animals/bunny/bunny_animations.png", 21, 21, 4, 6);
    bunny->SetMapWidth(mapWidth);
    bunny->SetMapHeight(mapHeight);
    bunny->SetTileSize(tileSize);

    // setup states
    auto wanderState = new WanderState(nodeList, mapData);
    wanderState->SetTileSize(tileSize, 4);
    auto searchForFoodState = new SearchFoodState();
    auto deathState = new DeadState();

    // setup conditions
    auto hungerCondition = new HungerCondition();
    auto deathCondition = new DeathCondition();

    // setup transitions
    auto toSearchFoodTransition = new Transition(searchForFoodState, hungerCondition);
    auto toDeathTransition = new Transition(deathState, deathCondition);

    wanderState->AddTransition(toSearchFoodTransition);
    searchForFoodState->AddTransition(toDeathTransition);

    FiniteStateMachine bunnyBehaviour;
    bunnyBehaviour.AddState(wanderState);
    bunnyBehaviour.AddState(searchForFoodState);
    bunnyBehaviour.AddState(deathState);
    bunnyBehaviour.SetCurrentState(wanderState);

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
        // if(IsKeyDown(KEY_SPACE))
        // {   
            //  grid->DrawGrid();
            //  grid->DrawMap(mapData);
             // draw path
            //  grid->DrawPath(bunny->GetPath());
         //    
        // }
        
        // draw bunny
        bunnyBehaviour.Update(bunny, GetFrameTime());
        bunny->Update(GetFrameTime());
        bunny->Draw();

        EndDrawing();
    }

    UnloadTexture(map); 
       
    CloseWindow();  
}




