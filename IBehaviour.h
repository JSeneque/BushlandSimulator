#pragma once

#include "raylib.h"

enum eBehaviourResult 
{
    SUCCESS,
    FAILURE,
    RUNNING
};

class Agent;

class IBehaviour {
public:
    // empty constructor and destructor for the base class
    IBehaviour() {}
    ~IBehaviour() {}

    // pure virtual function for executing the behaviour
    virtual void Update(Agent* agent, float deltaTime) = 0;

};