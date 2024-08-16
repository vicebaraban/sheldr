#include "bullet.h"
#include "creature.h"
#include <SFML/System/Vector2.hpp>


Bullet::Bullet(): Creature() {
    initVariables();
}


void Bullet::initVariables() {
    this->speed_x = 100.f * (1.f / FPS);
    this->speed_y = 100.f * (1.f / FPS);
    this->dx = 0.f;
    this->dy = 0.f;
}


void Bullet::setDirection(sf::Vector2f dir) {
    this->dx = dir.x;
    this->dy = dir.y;
}

void Bullet::update() {
    move(sf::Vector2f(this->speed_x * this->dx, this->speed_y * this->dy));
}