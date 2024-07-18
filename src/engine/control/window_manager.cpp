#include "window_manager.h"


WindowManager& WindowManager::get() {
    static WindowManager wm;
    return wm;
}

WindowManager::WindowManager() {
    m_window.create(sf::VideoMode(200, 200), "Test App");
}

void WindowManager::close() {
    m_window.close();
}

void WindowManager::clear() {
    m_window.clear();
}

void WindowManager::update() {
    m_window.display();
}

bool WindowManager::isOpen()
{
    return m_window.isOpen();
}

sf::RenderWindow& WindowManager::getRaw()
{
    return m_window;
}

void WindowManager::draw(const sf::Drawable& drawable)
{
    m_window.draw(drawable);
}

