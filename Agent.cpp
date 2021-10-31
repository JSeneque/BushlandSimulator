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
        if (frame > maxFrame) 
            frame = 0;
    }
    
    // get keyboard input just to test out the direction
    // matches the animation
    if (IsKeyDown(KEY_W))
    {
        _direction = UP;
        _position.y -= _moveSpeed * deltaTime;
    }
    if (IsKeyDown(KEY_S))
    {
        _direction = DOWN;
        _position.y += _moveSpeed * deltaTime;
    }
    if (IsKeyDown(KEY_A))
    {
        _direction = LEFT;
        _position.x -= _moveSpeed * deltaTime;
    }
    if (IsKeyDown(KEY_D))
    {
        _direction = RIGHT;
        _position.x += _moveSpeed * deltaTime;
    }
    
    //Vector2 force = {0,0};

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
    Rectangle animation {_width * frame, 21.0f, _width, _height};

    switch (_direction)
    {
        case UP:
            animation = {_width * frame, 21.0f, _width, _height};
            break;
        case DOWN:
            animation = {_width * frame, 0.0f, _width, _height};
            break;
        case LEFT:
            animation = {_width * frame, 63.0f, _width, _height};
            break;
        case RIGHT:
            animation = {_width * frame, 42.0f, _width, _height};
            break;
    }
    
    Rectangle dest{_position.x - _width / 2, _position.y - _height / 2, 4.0f * _width, 4.0f * _height};
    DrawTexturePro(_texture, animation, dest, Vector2{}, 0.0f, WHITE);
}

// void Agent::AddBehaviour(IBehaviour* behaviour)
// {
//     _behaviours.push_back(behaviour);
// }



