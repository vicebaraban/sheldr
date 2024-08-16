#include "state_manager.h"


State::State(StateData* state_data) {
	this->state_data = state_data;
	this->states = state_data->states;
}

State::~State() {}

// void sheldr::State::update(const float &dt) {
	
// }

// void sheldr::State::render() {

// }