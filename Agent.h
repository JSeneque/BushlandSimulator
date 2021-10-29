#pragma once

#include "raylib.h"
#include <vector>
#include <string>

//class IBehaviour;

class Agent{
public:
    Agent();
    Agent(Vector2 pos, const char *file, float width, float height, int frames, int animations);

    virtual ~Agent() ;

    // update the agent and its behaviours
    virtual void Update(float deltaTime);
    // draw the agent
    virtual void Draw();
    // add a behaviour to the agent
    //void AddBehaviour(IBehaviour* behaviour);

    void SetPosition(Vector2 pos);
    Vector2 GetPosition();

    float GetWidth()
    {
        return _width;
    }

    float GetHeight()
    {
        return _height;
    }

    int GetNumberOfFrames()
    {
        return _numberOfFrames;
    }

    int GetNumberOfAnimations()
    {
        return _numberOfAnimations;
    }

private:
    Vector2 _position {0.0f, 0.0f};
    Vector2 _velocity;
    float _maxSpeed{20.0f};
    float _radius {5.0f};
    Color _colour {BLUE};

    //std::vector<IBehaviour*> _behaviours;

    Texture2D _texture;
    float _width{};
    float _height{};
    int _numberOfFrames;
    int _numberOfAnimations;

    float runningTime {};
    int frame{};
    const int maxFrame{4};
    const float updateTime{1.0f/12.0f};
};