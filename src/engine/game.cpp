#include "game.h"


Game::Game() {
    
}


void Game::runMainGameLoop() {

    auto& window = WindowManager::get();
    ProcessEventsManager eventHandler;

    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen()) {

        eventHandler.handleEvents();

        window.clear();
        window.draw(shape);
        window.update();
    }
}
