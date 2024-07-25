#include "game.h"


Game::Game() {
    
}


void Game::runMainGameLoop() {

    auto& window = sheldr::WindowManager::get();
    sheldr::ProcessEventsManager eventHandler;

    sheldr::TextureManager::loadTexture("test_texture", "assets/square.png");

    sheldr::Sprite test_sprite(sheldr::TextureManager::getTexture("test_texture"));

    while (window.isOpen()) {

        eventHandler.handleEvents();

        window.clear();
        window.draw(test_sprite);
        window.update();
    }
}
