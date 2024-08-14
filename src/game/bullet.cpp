#include "bullet.h"
#include <SFML/System/Vector2.hpp>


void Bullet::setDirection(sf::Vector2f dir) {
    dx = dir.x;
    dy = dir.y;
}

void Bullet::update() {
    move(sf::Vector2f(speed_x * dx, speed_y * dy));
}