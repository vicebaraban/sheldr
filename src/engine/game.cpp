#include "game.h"
#include "control/texture_manager.h"
#include "control/window_manager.h"
#include "utils/core_statistics_hub.h"
#include "utils/load.h"
#include "utils/simple_utils.h"
#include "values.h"
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Window.hpp>
#include <iostream>
#include <memory>
#include <string>
#include <vector>


Game::Game() {
    this->initWindow();
    this->initAssets();
    this->initVariables();
    this->initStateData();
    this->initStates();
}

void Game::initWindow() {
    sheldr::WindowManager::get();
}

void Game::initAssets() {
    loadImages();
}

void Game::initVariables() {
    this->fps = 30;
    this->time_per_frame = sf::seconds(1.f / this->fps);
}

void Game::initStateData() {
    this->state_data.states = &this->states;
}

void Game::initStates() {
	this->states.push(new PlayingState(&this->state_data));
}

void Game::run() {
    
    auto &window = sheldr::WindowManager::get();

    while (window.isOpen()) {
        
        updateSystem();
        sheldr::ProcessEventsManager::handleEvents();
        updateState();
        renderWindow();

    }
}



void Game::updateSystem() {
    sf::Time delta;
    this->dt = this->clock.restart();
    while (this->dt < this->time_per_frame) {

            delta = this->clock.restart();
            this->dt += delta;

        }
    
    this->statistics_text.update(this->dt);
}

void Game::renderWindow() {
    auto &window = sheldr::WindowManager::get();
    
    window.clear();

    if (!this->states.empty()) {
		this->states.top()->render();
    }
    
    renderSystemInfo();
	window.display();
}

void Game::renderSystemInfo() {
    auto &window = sheldr::WindowManager::get();
    window.draw(statistics_text.getInfoText());
}

void Game::updateState() {
	if (!this->states.empty()) {
        this->states.top()->update(this->dt.asSeconds());

        // if (this->states.top()->getQuit()) {
        //     this->states.top()->endState();
        //     delete this->states.top();
        //     this->states.pop();
        // }
	}

}