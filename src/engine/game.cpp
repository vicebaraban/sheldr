#include "game.h"
#include "control/texture_manager.h"
#include "control/window_manager.h"
#include "utils/core_statistics_hub.h"
#include "utils/simple_utils.h"
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <iostream>
#include <string>
#include <vector>


Game::Game() {}


void Game::runMainGameLoop() {
    
    sf::Clock clock;

    auto& window = sheldr::WindowManager::get();
    // window.setFramerateLimit(30);

    utils::StatisticsHub statistics_text;
    // window.setVerticalSyncEnabled(true);

    loadImages();
    player.setPosition(sf::Vector2f(30.f, 30.f));
    player.setSpriteTexture(sheldr::TextureManager::getTexture("test_texture"));

    sf::Time time_per_frame = sf::seconds(1.f / 30.f);
    // sf::Time current_time = sf::seconds(0.f);

    while (window.isOpen()) {
        
        sf::Time current_time = clock.restart();
        std::vector<std::string> input_buttons;
        while (current_time < time_per_frame) {

            sf::Time dt = clock.restart();
            current_time += dt;


        }
        statistics_text.update(current_time);

        input_buttons = sheldr::ProcessEventsManager::handleEvents();

        processEvents(input_buttons);


        // sheldr::ProcessEventsManager::handleEvents();

        player.update();

        for (Bullet b : bullet_container) {
            b.update();
        }

        window.clear();
        window.draw(player.getSprite());
        std::cout << bullet_container.size() << "\n";
        for (Bullet b : bullet_container) {
            window.draw(b.getSprite());
            // std::cout << b.getPosition().x << "\n";
        }
        window.draw(statistics_text.getInfoText());
        window.update();
    }
}


void Game::processEvents(std::vector<std::string> input_buttons) {

    for (int i = 0; i < input_buttons.size(); i++) {
        // std::cout << input_buttons[i] << "\n";
        if (input_buttons[i] == "+space") {
            // std::cout << "1\n";
            bullet_container.push_back(Bullet());
            bullet_container[-1].setPosition(player.getPosition());
            bullet_container[-1].setSpriteTexture(sheldr::TextureManager::getTexture("bullet")); 
            bullet_container[-1].setDirection(player.getTargetDirection());      
        }
    }


}