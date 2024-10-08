#ifndef WINDOW_MANAGER_H_
#define WINDOW_MANAGER_H_

#include <SFML/Graphics.hpp>
#include "../sprite/sprite_group.h"

namespace sheldr {

    class WindowManager {
    public:

        static WindowManager& get();

        void close();

        void clear();
        
        void display();

        void setFramerateLimit(unsigned int);

        void setVerticalSyncEnabled(bool);

        bool isOpen();

        sf::RenderWindow& getRaw();

        void draw(const sf::Drawable&);

        void drawGroup(sheldr::SpriteGroup*);

    private:

        WindowManager();

        sf::RenderWindow m_window;

    };

}

#endif  // WINDOW_MANAGER_H_