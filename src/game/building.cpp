#include "building.h"
#include <iostream>


Building::Building(): Creature() {
    this->initVariables();
    this->initCollider();
}

void Building::initCollider() {
    this->collider = new RectangleCollider();
    this->collider->settings(this->position, this->size);
}


void Building::initVariables() {
    this->size = sf::Vector2f(64.f * 5.f, 64.f * 5.f);
}


void Building::update() {
    this->move();
    this->collider->update(this->position);
    // std::cout << "2\n";
}

RectangleCollider &Building::getCollider() {
    return *this->collider;
}