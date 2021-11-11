#include "Agent.h"
#include "raymath.h"
#include "Graph.h"
#include "IBehaviour.h"
#include <iostream>


Agent::Agent() { _position = Vector2{}; }

Agent::Agent(Vector2 pos, const char *file, float width, float height, int frames, int animations) : 
    _position {pos},
    _width {width},
    _height {height},
    _numberOfFrames {frames},
    _numberOfAnimations {animations}
{
    _texture = LoadTexture(file);
    _hunger = _maxHunger;
}


Agent::~Agent() { UnloadTexture(_texture); }

void Agent::SetPosition(Vector2 pos) { _position = pos; }
Vector2 Agent::GetPosition() { return _position; }

void Agent::Update(float deltaTime)
{
    if (!_isDead)
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

        // lower hunger value
        UpdateHunger(deltaTime);


        if(_isMoving)
        {
            if (_path.size() == 0)
                return;

            auto id = _path[_pathIndex]->id;

            float ix = (id % _mapWidth) * _tileSize * 4 ;
            float iy = (id / _mapWidth) * _tileSize * 4 ;

            Vector2 targetPosition = {ix, iy};
            Vector2 toTarget;
            // create a direction to the new position
            if (targetPosition.x == _position.x && targetPosition.y == _position.y)
            {
                toTarget = {0,0};
            }
            else
            {
                toTarget = Vector2Subtract(targetPosition, _position);
                //normalise the vector
                toTarget = Vector2Normalize(toTarget);
            }
            _hasArrived = false;
            _position = Vector2Add(_position, Vector2Scale(toTarget, _moveSpeed * deltaTime));
            float distance = Vector2Distance(_position, targetPosition);

            if (distance < 1.5)
            {
                _currentID = _path[_pathIndex]->id;
                _position.x = (id % _mapWidth) * _tileSize * 4 ;
                _position.y = (id / _mapWidth) * _tileSize * 4 ;
                _pathIndex++;

            }

            if (_pathIndex >= _path.size())
            {
                _pathIndex = 0;
                _isMoving = false;
                _hasArrived = true;
            }

            // determine direction travelled to we can play the right animation
            if (_currentID == _path[_pathIndex]->id - 1) {
                _direction = RIGHT;
            } else if (_currentID == _path[_pathIndex]->id + 1) {
                _direction = LEFT;
            }  else if(_currentID == _path[_pathIndex]->id - _mapHeight) {
                _direction = DOWN;
            } else if(_currentID == _path[_pathIndex]->id + _mapHeight) {
                _direction = UP;
            }
        }
        else {
            _direction = IDLE;
        }
    }
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
        default:
            animation = {_width * frame, 21.0f, _width, _height};
    }
    
    Rectangle dest{_position.x - _width / 2, _position.y - _height / 2, 4.0f * _width, 4.0f * _height};
    DrawTexturePro(_texture, animation, dest, Vector2{}, 0.0f, WHITE);
}

void Agent::AddBehaviour(IBehaviour* behaviour) { _behaviours.push_back(behaviour); }
void Agent::SetPath(std::vector<const Node*> path) { 
    _path = path; 
    _pathIndex = 0;    
}
float Agent::GetHunger() const { return _hunger; }
void Agent::ResetHunger() { _hunger = _maxHunger; }
bool Agent::IsMoving() { return _isMoving; }
void Agent::SetIsMoving(const bool value) { _isMoving = value; }
float Agent::GetWidth() { return _width; }
float Agent::GetHeight() { return _height; }
int Agent::GetNumberOfFrames() { return _numberOfFrames; }
int Agent::GetNumberOfAnimations() { return _numberOfAnimations; }
void Agent::SetMapWidth(int width) { _mapWidth = width; }
void Agent::SetMapHeight(int height) { _mapHeight = height; }
void Agent::SetTileSize(int tileSize) { _tileSize = tileSize; }
void Agent::SetHasArrived(const bool value) { _hasArrived = value;}
bool Agent::GetHasArrived() { return _hasArrived;}
void Agent::SetIsEating() { _isEating = true; }

const int Agent::GetPathIndex() { return _pathIndex;}

void Agent::ReplenishHunger(float deltaTime) {
     
}

void Agent::SetHunger(const float value) { _hunger = value; }
const float Agent::GetMaxHunger() { return _maxHunger; }


void Agent::UpdateHunger(float deltaTime)
{
    if (_isEating) {
        _hunger += (20 * deltaTime);
        if (_hunger >= _maxHunger) {
            _isEating = false;
        }
    } else {
        _hunger -= deltaTime;

        if (_hunger <= 0.0f) {
            _hunger = 0.0f;
            _isDead = true;
        }
    }
}



