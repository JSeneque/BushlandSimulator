#pragma once
#include <vector>

class State;
class Transition;
class Condition;
class Agent;

class FiniteStateMachine {
public:
    FiniteStateMachine() : _currentState (nullptr) {}
    ~FiniteStateMachine() {
        for (auto s : _states)
            delete s;
        
        for (auto t : _transitions)
            delete t;
        for (auto c : _conditions)
            delete c;
    }

    State* AddState(State* state) {
        _states.push_back(state);
        return state;
    }

    Transition* AddState(Transition* transition) {
        _transitions.push_back(transition);
        return transition;
    }

    Condition* AddState(Condition* condition) {
        _conditions.push_back(condition);
        return condition;
    }

    void SetCurrentState(State* state) {  _currentState = state;}

    virtual void Update(Agent* agent, float deltaTime);

protected:
    std::vector<State*> _states;
    std::vector<Transition*> _transitions;
    std::vector<Condition*> _conditions;

    State* _currentState;

};