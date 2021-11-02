#include "State.h"
#include "Transition.h"



Transition* State::GetTriggeredTransition(Agent* agent)
{
    for(auto transition : _transitions)
    {
        if (transition->HasTriggered(agent))
            return transition;
    }

    return nullptr;
}