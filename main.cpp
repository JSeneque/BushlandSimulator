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
    
    std::vector<Node> nodeList;
    Grid* grid = new Grid(10, 10, 16);

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
    auto path = dijkstrasSearch.DijkstrasSearch(&nodeList[22], &nodeList[57]);

    

    const int tileSize = 16;
    
    InitWindow(windowWidth, windowHeight, "BushlandSimulator");

    Texture2D map = LoadTexture("tileset/world_map.png");
    
    Agent* bunny = new Agent(Vector2{320,320}, "animals/bunny/bunny_animations.png", 21, 21, 4, 6);

    SetTargetFPS(60);

    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        Vector2 mapPos {0,0};
        // draw map
        DrawTextureEx(map, mapPos, 0.0, 4.0, WHITE);
        grid->DrawGrid();
        // draw path
        grid->DrawPath(path);
        // highlight obstacles
        grid->DrawMap(mapData);
        // draw bunny
        bunny->Update(GetFrameTime());
        bunny->Draw();

        EndDrawing();
    }

    UnloadTexture(map); 
       
    CloseWindow();  
}




