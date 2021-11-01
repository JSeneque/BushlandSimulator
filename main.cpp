#include "raylib.h"
#include "Agent.h"
#include "Dijkstras.h"
#include "Graph.h"
#include <vector>
#include <iostream>
#include "Grid.h"

int main()
{
    const int windowWidth{640};
    const int windowHeight{640};
    const int mapWidth = 10;
    const int mapHeight = 10;
    const int tileSize = 16;
    
    std::vector<Node> nodeList;
    Grid* grid = new Grid(mapWidth, mapHeight, tileSize);

    std::vector<int> mapData = {1,1,1,1,1,1,1,1,1,1,
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

    Dijkstras dijkstrasSearch;
    auto path = dijkstrasSearch.DijkstrasSearch(&nodeList[22], &nodeList[67]);

    InitWindow(windowWidth, windowHeight, "BushlandSimulator");

    Texture2D map = LoadTexture("tileset/world_map.png");
    
    Agent* bunny = new Agent(Vector2{112,112}, "animals/bunny/bunny_animations.png", 21, 21, 4, 6);
    bunny->SetMapWidth(mapWidth);
    bunny->SetMapHeight(mapHeight);
    bunny->SetTileSize(tileSize);

    SetTargetFPS(60);

    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        Vector2 mapPos {0,0};
        // draw map
        DrawTextureEx(map, mapPos, 0.0, 4.0, WHITE);
        
        
        bunny->SetPath(path);
        //bunny->FollowPath(mapWidth, tileSize, path);
        // highlight obstacles
        if(IsKeyDown(KEY_SPACE))
        {   
            grid->DrawGrid();
            grid->DrawMap(mapData);
            // draw path
            grid->DrawPath(path);
        }
        
        // draw bunny
        bunny->Update(GetFrameTime());
        bunny->Draw();

        EndDrawing();
    }

    UnloadTexture(map); 
       
    CloseWindow();  
}




