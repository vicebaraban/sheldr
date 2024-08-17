#include "bullet.h"
#include "creature.h"
#include <SFML/System/Vector2.hpp>


Bullet::Bullet(): Creature() {
    this->initVariables();
    this->initCollider();
}

void Bullet::initCollider() {
    this->collider = new RectangleCollider();
    this->collider->settings(this->position, this->size);
}


void Bullet::initVariables() {
    this->size = sf::Vector2f(14.f, 14.f);
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
    this->move(sf::Vector2f(this->speed_x * this->dx, this->speed_y * this->dy));
    this->collider->update(this->position);
}

RectangleCollider &Bullet::getCollider() {
    return *this->collider;
}