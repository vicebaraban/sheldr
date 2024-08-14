#include "creature.h"
#include <SFML/System/Vector2.hpp>


void Creature::setSpriteTexture(sf::Texture* texture) {
    sprite.setTexture(*texture);
}

void Creature::setPosition(sf::Vector2f pos) {
    position = pos;
}

sheldr::Sprite &Creature::getSprite() {
    return sprite;
}

sf::Vector2f Creature::getPosition() {
    return position;
}

void Creature::moveX(float delta) {
    position.x += delta;
    sprite.setPosition(position);
}

void Creature::moveY(float delta) {
    position.y += delta;
    sprite.setPosition(position);
}

void Creature::move(sf::Vector2f delta) {
    position.x += delta.x;
    position.y += delta.y;
    sprite.setPosition(position);
}

void Creature::setDirectionX(int x) {
    dx = x;
}

void Creature::setDirectionY(int y) {
    dy = y;
}

void Creature::update() {}
