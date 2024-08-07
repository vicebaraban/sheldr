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
    bool w_is_pressed = false;
    bool a_is_pressed = false;
    bool s_is_pressed = false;
    bool d_is_pressed = false;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        w_is_pressed = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        a_is_pressed = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        s_is_pressed = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        d_is_pressed = true;
    }

    if (w_is_pressed == s_is_pressed) {
        this->setDirectionY(0);
    }
    else if (w_is_pressed && !s_is_pressed) {
        this->setDirectionY(-1);
    }
    else {
        this->setDirectionY(1);
    }

    if (a_is_pressed == d_is_pressed) {
        this->setDirectionX(0);
    }
    else if (a_is_pressed && !d_is_pressed) {
        this->setDirectionX(-1);
    }
    else {
        this->setDirectionX(1);
    }
}