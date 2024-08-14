#ifndef CORE_STATISTICS_HUB_H_
#define CORE_STATISTICS_HUB_H_


#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Text.hpp>
#include "../control/window_manager.h"


namespace utils {


    class StatisticsHub {
    public:

        StatisticsHub();
        
        void showFPS(bool);
        void showResolution(bool);

        void update(sf::Time);

        sf::Text& getInfoText();
    
    private:
        sf::Text text_hub;
        sf::Font my_font;

        bool show_fps = false;
        bool show_resolution = false;

        sf::Time update_time;
        unsigned int num_frames;
    };


}

#endif  // CORE_STATISTICS_HUB_H_