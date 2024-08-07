#include "creature.h"
#include <SFML/System/Vector2.hpp>


void Creature::setSpriteTexture(sf::Texture* texture) {
    sprite.setTexture(*texture);
}

sheldr::Sprite Creature::getSprite() {
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

void Creature::update() {
    inputScan();
    move(sf::Vector2f(dx * speedX, dy * speedY));
}

void Creature::inputScan() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        this->setDirectionY(-1);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        this->setDirectionX(-1);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        this->setDirectionY(1);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        this->setDirectionX(1);
    }
}