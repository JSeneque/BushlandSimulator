#include "Agent.h"
#include "raymath.h"
//#include "IBehaviour.h"

Agent::Agent()
{
    _position = Vector2{};
}

Agent::Agent(Vector2 pos, const char *file, float width, float height, int frames, int animations) : 
    _position {pos},
    _width {width},
    _height {height},
    _numberOfFrames {frames},
    _numberOfAnimations {animations}
{
    _texture = LoadTexture(file);
}

Agent::~Agent()
{
    UnloadTexture(_texture); 
}

void Agent::SetPosition(Vector2 pos)
{
    _position = pos;
}

Vector2 Agent::GetPosition()
{
    return _position;
}

void Agent::Update(float deltaTime)
{
    // update animation frame
    runningTime += deltaTime;
    if(runningTime >= updateTime)
    {
        frame++;
        runningTime = 0.0f;
        if (frame > maxFrame) frame = 0;
    }
    
    Vector2 force = {0,0};

    // // for each behaviour in the behavious list
    // for (auto b : _behaviours)
    // {
    //     force = Vector2Add(force, b->Update(this, deltaTime));
    // }

    // _velocity = Vector2Add(_velocity, Vector2Scale(force, deltaTime));
    

    // // check if the magitude of the velocity
    // if(Vector2Length(_velocity) > _maxSpeed)
    // {
    //     _velocity = Vector2Scale(Vector2Normalize(_velocity), _maxSpeed);
    // }

    // _position = Vector2Add(_position, _velocity);

}

void Agent::Draw()
{
    Rectangle bunnyAnimDown{_width/_numberOfFrames * frame, 0.0f, _width/_numberOfFrames, _height/_numberOfFrames};
    Rectangle bunnyAnimUp{_width/_numberOfFrames * frame, 21.0f, _width/_numberOfFrames, _height/_numberOfFrames};
    Rectangle bunnyAnimRight{_width/_numberOfFrames * frame, 42.0f, _width/_numberOfFrames, _height/_numberOfFrames};
    Rectangle bunnyAnimLeft{_width * frame, 63.0f, _width, _height};
    Rectangle dest{_position.x, _position.y, 4.0f * _width, 4.0f * _height};
    DrawTexturePro(_texture, bunnyAnimLeft, dest, Vector2{}, 0.0f, WHITE);
}

// void Agent::AddBehaviour(IBehaviour* behaviour)
// {
//     _behaviours.push_back(behaviour);
// }



