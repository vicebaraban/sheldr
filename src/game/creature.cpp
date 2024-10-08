#include "creature.h"


Creature::Creature() {
    this->initVariables();
}


void Creature::initVariables() {
    this->position = sf::Vector2f(0.f, 0.f);
    this->dx = 0;
    this->dy = 0;
    this->speed_x = 2;
    this->speed_y = 2;
}

void Creature::setSpriteTexture(sf::Texture* texture) {
    this->sprite.setTexture(*texture);
}

void Creature::setPosition(sf::Vector2f pos) {
    this->position = pos;
}

sheldr::Sprite &Creature::getSprite() {
    return this->sprite;
}

sf::Vector2f Creature::getPosition() {
    return this->position;
}

void Creature::moveX(float delta) {
    this->position.x += delta;
    this->sprite.setPosition(this->position);
}

void Creature::moveY(float delta) {
    this->position.y += delta;
    this->sprite.setPosition(this->position);
}

void Creature::move(sf::Vector2f delta) {
    this->position.x += delta.x;
    this->position.y += delta.y;
    this->sprite.setPosition(this->position);
}

void Creature::move() {
    this->sprite.setPosition(this->position);
}

void Creature::setDirectionX(float x) {
    this->dx = x;
}

void Creature::setDirectionY(float y) {
    this->dy = y;
}

void Creature::update() {
    this->sprite.setPosition(this->position);
}

void Creature::setSpriteScale(sf::Vector2f scale) {
    this->sprite.setScale(scale);
}

void Creature::setSpeedX(float v) {
    this->speed_x = v;
}

void Creature::setSpeedY(float v) {
    this->speed_y = v;
}