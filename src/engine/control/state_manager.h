#ifndef STATE_MANAGER_H_
#define STATE_MANAGER_H_


#include <stack>


class Player;


class State;


class StateData {

public:
    StateData() {};

    std::stack<State *> *states;

};


class State {

protected:
    StateData *state_data;
    std::stack<State*> *states;

public:
    State(StateData *state_data);
    virtual ~State();   

    virtual void render() = 0;
    virtual void update(const float &dt) = 0;

};



#endif  // STATE_MANAGER_H_