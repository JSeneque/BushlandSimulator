#pragma once

#include "raylib.h"
#include <vector>
#include <string>
#include <list>
#include "UIBar.h"
#include "UIText.h"

class IBehaviour;
class Node;

enum Direction
{
    UP, DOWN, LEFT, RIGHT, IDLE
};


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
    void AddBehaviour(IBehaviour* behaviour);
    void FollowPath(const int mapWidth, const int tileSize, std::vector<const Node*> path);
    void SetPosition(Vector2 pos);
    Vector2 GetPosition();
    float GetWidth();
    float GetHeight();
    int GetNumberOfFrames();
    int GetNumberOfAnimations();
    void SetMapWidth(int width);
    void SetMapHeight(int height);
    void SetTileSize(int tileSize);
    void SetPath(std::vector<const Node*> path);
    std::vector<const Node*> GetPath() { return _path;}
    float GetHunger() const;
    void ResetHunger();
    void UpdateHunger(float deltaTime);
    bool IsMoving();
    void SetIsMoving(const bool value);
    void SetHasArrived(const bool value);
    bool GetHasArrived();
    void ReplenishHunger(float deltaTime);
    void SetIsEating();
    const int GetPathIndex();
    void SetHunger(const float value);
    const float GetMaxHunger();
    const void DrawUI();
    const void DrawStateText(char* text);

private:
    Vector2 _position {0.0f, 0.0f};
    Vector2 _velocity;
    float _moveSpeed{150.0f};
    float _radius {5.0f};
    Color _colour {BLUE};
    bool _isDead{false};
    bool _hasArrived {false};
    bool _isEating{false};

    std::vector<IBehaviour*> _behaviours;

    Texture2D _texture;
    float _width{};
    float _height{};
    int _numberOfFrames;
    int _numberOfAnimations;

    float runningTime {};
    int frame{};
    const int maxFrame{4};
    const float updateTime{1.0f/12.0f};
    Direction _direction;

    std::vector<const Node*> _path;
    int _mapWidth;
    int _mapHeight;
    int _tileSize;
    int _pathIndex{};
    bool _isMoving = false;
    int _currentID;

    // animal traits
    float _hunger{};
    float _maxHunger{25.0f};
    float _thirst{50.0};

    // UI
    UIBar *hungerBar = new UIBar();
    UIText *stateText = new UIText("", 10, WHITE);

};