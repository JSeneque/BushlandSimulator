#include "EatingState.h"
#include "Agent.h"

void EatingState::onUpdate(Agent* agent, float deltaTime) {
    agent->SetHunger(agent->GetMaxHunger());
}