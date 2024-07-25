#include "game.h"
#include "sprite/sprite.h"
#include <SFML/Graphics/Texture.hpp>


Game::Game() {
    
}


void Game::runMainGameLoop() {

    auto& window = sheldr::WindowManager::get();
    sheldr::ProcessEventsManager eventHandler;
    sf::Texture texture;
    texture.loadFromFile("assets/square.png");
    sheldr::Sprite figure(texture);

    while (window.isOpen()) {

        eventHandler.handleEvents();

        window.clear();
        window.draw(figure);
        window.update();
    }
}
