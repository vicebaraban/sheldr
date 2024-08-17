#include "player.h"
#include "bullet.h"
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Cursor.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <iostream>


Player::Player(): Creature() {
    this->initVariables();
    this->initCollider();
}

RectangleCollider &Player::getCollider() {
    return *this->collider;
}

void Player::initVariables() {
    this->speed_x = 30.f * (1.f / FPS);
    this->speed_y = 30.f * (1.f / FPS);
    this->size = sf::Vector2f(64.f, 32.f);
}

void Player::initCollider() {
    this->collider = new RectangleCollider();
    this->collider->settings(this->position, this->size);
}

void Player::update() {
    this->inputScan();
    this->updateTargetDirection();
    this->move(sf::Vector2f(this->dx * this->speed_x, this->dy * this->speed_y));
    this->collider->update(this->position);
    // std::cout << dx * speedX << " " << dy * speedY << "\n";
}

void Player::inputScan() {
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
        this->dy = 0.f;
    }
    else if (w_is_pressed && !s_is_pressed) {
        this->dy = -1.f;
    }
    else {
        this->dy = 1.f;
    }

    if (a_is_pressed == d_is_pressed) {
        this->dx = 0.f;
    }
    else if (a_is_pressed && !d_is_pressed) {
        this->dx = -1.f;
    }
    else {
        this->dx = 1.f;
    }
    if (this->dx != 0.f && this->dy != 0.f) {
        this->dx = 1 / sqrt(2) * this->dx;
        this->dy = 1 / sqrt(2) * this->dy;
    }
}

void Player::updateTargetDirection() {
    this->target_direction = calculateDirection(this->position,
     sheldr::ProcessEventsManager::mousePosition());
}

// void Player::shoot() {
//     Bullet(position, target_direction);
// }

sf::Vector2f Player::getTargetDirection() {
    return this->target_direction;
}