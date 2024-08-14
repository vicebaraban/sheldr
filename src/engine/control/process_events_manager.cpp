#include "process_events_manager.h"
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <iostream>
#include <string>


std::vector<std::string> sheldr::ProcessEventsManager::handleEvents() {
    auto& window = sheldr::WindowManager::get().getRaw();

    std::vector<std::string> input_buttons;
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();

        else if (event.type == sf::Event::KeyPressed || event.type == sf::Event::KeyReleased) {
            std::string input_button;

            // std::cout << "2\n";

            if (event.type == sf::Event::KeyPressed) {
                input_button = "+";
            }
            else {
                input_button = "-";
            }

            if (event.key.code == sf::Keyboard::W) {
                input_button += "w";
            }
            else if (event.key.code == sf::Keyboard::A) {
                input_button += "a";
            }
            else if (event.key.code == sf::Keyboard::S) {
                input_button += "s";
            }
            else if (event.key.code == sf::Keyboard::D) {
                input_button += "d";
            }
            else if (event.key.code == sf::Keyboard::Space) {
                input_button += "space";
            }

            input_buttons.push_back(input_button);

        }

        else if (event.type == sf::Event::MouseButtonPressed) {
            input_buttons.push_back("+mouse");
        }
        else if (event.type == sf::Event::MouseButtonReleased) {
            input_buttons.push_back("-mouse");
        }
        
    }
    return input_buttons;
}

sf::Vector2f sheldr::ProcessEventsManager::mousePosition() {

    auto& window = sheldr::WindowManager::get().getRaw();

    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    return window.mapPixelToCoords(mousePosition);
}