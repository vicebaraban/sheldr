#include "core_statistics_hub.h"
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>
#include <string>


namespace utils {

    StatisticsHub::StatisticsHub() {
        my_font.loadFromFile("assets/Sansation.ttf");
        text_hub.setFont(my_font);
        text_hub.setPosition(5.f, 5.f);
	    text_hub.setCharacterSize(25u);
    };

    void StatisticsHub::showFPS(bool t) {
        show_fps = t;
    }

    void StatisticsHub::showResolution(bool t) {
        show_resolution = t;
    }

    sf::Text& StatisticsHub::getInfoText() {
        return text_hub;
    }

    void StatisticsHub::update(sf::Time dt) {
        update_time += dt;
        num_frames += 1;
        if (update_time >= sf::seconds(1.0f)) {
            auto& window = sheldr::WindowManager::get().getRaw();
            sf::Vector2u res = window.getSize();
            text_hub.setString("FPS: " + std::to_string(num_frames) + "\n" +
                                std::to_string(res.x) + "x" + std::to_string(res.y));

            update_time = sf::seconds(0.f);
            num_frames = 0;
        }

    }

}