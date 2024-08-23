#include "game.h"


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

    // sf::Vector2f t = sf::Vector2f(2, 4);
    // sf::Vector2f e = sf::Vector2f(1, 2);
    // sf::Vector2f a = t + e;
    // std::cout << a.x << " " << a.y << "\n";

    // bool t = rectInRect(
    //     1, 1, 2, 2, -80, 3, 4, 4
    // );
    // if (t) {
    //     std::cout << "collide\n";
    // }

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