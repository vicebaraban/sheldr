#ifndef PROCESS_EVENTS_MANAGER_H_
#define PROCESS_EVENTS_MANAGER_H_

#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <string>
#include "window_manager.h"


namespace sheldr {

    class ProcessEventsManager {

        ProcessEventsManager();

    public:

        static sf::Vector2f mousePosition();
        
        static std::string handleEvents();

    };

}

#endif  // PROCESS_EVENTS_MANAGER_H_