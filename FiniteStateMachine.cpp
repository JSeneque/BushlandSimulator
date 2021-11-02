#include "FiniteStateMachine.h"
#include "Agent.h"
#include "Transition.h"
#include "State.h"

void FiniteStateMachine::Update(Agent* agent, float deltaTime)
{
    if(_currentState != nullptr)
    {
        Transition* transition = _currentState->GetTriggeredTransition(agent);

        if(transition != nullptr)
        {
            _currentState->onExit(agent);
            _currentState = transition->GetTargetState();
            _currentState->onEnter(agent);
        }

        _currentState->onUpdate(agent, deltaTime);
    }
}