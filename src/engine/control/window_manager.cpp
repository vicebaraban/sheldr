#include "window_manager.h"


sheldr::WindowManager& sheldr::WindowManager::get() {
    static WindowManager wm;
    return wm;
}

sheldr::WindowManager::WindowManager() {

    sf::ContextSettings contextSettings;
    contextSettings.depthBits = 24;
    contextSettings.stencilBits = 8;
    contextSettings.antialiasingLevel = 0;
    contextSettings.majorVersion = 3;
    contextSettings.minorVersion = 3;

    m_window.create(sf::VideoMode::getDesktopMode(), 
                    "Test App", 
                    sf::Style::Close,
                    contextSettings);
}

void sheldr::WindowManager::close() {
    m_window.close();
}

void sheldr::WindowManager::clear() {
    m_window.clear();
}

void sheldr::WindowManager::display() {
    m_window.display();
}

bool sheldr::WindowManager::isOpen() {
    return m_window.isOpen();
}

sf::RenderWindow& sheldr::WindowManager::getRaw() {
    return m_window;
}

void sheldr::WindowManager::draw(const sf::Drawable& drawable) {
    m_window.draw(drawable);
}

void sheldr::WindowManager::setFramerateLimit(unsigned int fps) {
    m_window.setFramerateLimit(fps);
}

void sheldr::WindowManager::setVerticalSyncEnabled(bool t) {
    m_window.setVerticalSyncEnabled(t);
}
// void sheldr::WindowManager::drawGroup(sheldr::SpriteGroup* group) {
//         for (sheldr::Sprite sprite : group->sprites()) {
//         m_window.draw(sprite);
//     }
// }

