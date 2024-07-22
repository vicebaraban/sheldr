#include "process_events_manager.h"


void sheldr::ProcessEventsManager::handleEvents() {
    auto& window = sheldr::WindowManager::get().getRaw();

    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}