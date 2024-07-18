#include "process_events_manager.h"


void ProcessEventsManager::handleEvents() {
    auto& window = WindowManager::get().getRaw();

    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}