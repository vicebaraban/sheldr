#include "game.h"
#include "utils/simple_utils.h"
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <iostream>


Game::Game() {}


void Game::runMainGameLoop() {

    auto& window = sheldr::WindowManager::get();
    window.setFramerateLimit(160);

    sheldr::TextureManager::loadTexture("test_texture", "assets/square.png");

    Creature test_sprite(sf::Vector2f(1, 2));
    test_sprite.setSpriteTexture(sheldr::TextureManager::getTexture("test_texture"));

    int input_stack_move_w = 0;
    int input_stack_move_s = 0;
    int input_stack_move_a = 0;
    int input_stack_move_d = 0;

    while (window.isOpen()) {

        std::vector<std::string> input_buttons = sheldr::ProcessEventsManager::handleEvents();

        test_sprite.update();

        window.clear();
        window.draw(test_sprite.getSprite());
        window.update();
    }
}
