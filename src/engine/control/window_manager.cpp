#include "window_manager.h"


sheldr::WindowManager& sheldr::WindowManager::get() {
    static WindowManager wm;
    return wm;
}

sheldr::WindowManager::WindowManager() {
    m_window.create(sf::VideoMode(200, 200), "Test App");
}

void sheldr::WindowManager::close() {
    m_window.close();
}

void sheldr::WindowManager::clear() {
    m_window.clear();
}

void sheldr::WindowManager::update() {
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

void sheldr::WindowManager::drawGroup(sheldr::SpriteGroup& group) {
        for (sheldr::Sprite &sprite : group.sprites()) {
        m_window.draw(sprite);
    }
}

