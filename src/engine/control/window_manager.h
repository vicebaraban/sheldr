#ifndef WINDOW_MANAGER_H_
#define WINDOW_MANAGER_H_

#include <SFML/Graphics.hpp>

namespace sf {
    class Window;
}


class WindowManager {
public:

    static WindowManager& get();

    void close();

    void clear();
    
    void update();

    bool isOpen();

    sf::RenderWindow& getRaw();

    void draw(const sf::Drawable& drawable);

private:

    WindowManager();

    sf::RenderWindow m_window;

};

#endif  // WINDOW_MANAGER_H_