#include "raylib.h"
#include "Agent.h"

int main()
{
    const int windowWidth{640};
    const int windowHeight{640};

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

        // draw bunny
        bunny->Update(GetFrameTime());
        bunny->Draw();

        EndDrawing();
    }

    UnloadTexture(map); 
       

    CloseWindow();  
}


