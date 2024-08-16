#include "playing_state.h"
#include <SFML/Window/Keyboard.hpp>
#include <iostream>


PlayingState::PlayingState(StateData* state_data): State(state_data) {
    this->initPlayer();
}

PlayingState::~PlayingState() {}

void PlayingState::initPlayer() {
    this->player = new Player();
    this->player->setSpriteTexture(sheldr::TextureManager::getTexture("test_texture"));
    this->player->setPosition(sf::Vector2f(30.f, 30.f));
}

void PlayingState::render() {
    auto &window = sheldr::WindowManager::get();
    window.draw(player->getSprite());
    for (Bullet *b : bullet_container) {
        window.draw(b->getSprite());
    }
}

void PlayingState::update(const float &dt) {

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        Bullet *b = new Bullet();
        b->setPosition(player->getPosition());
        b->setSpriteTexture(sheldr::TextureManager::getTexture("bullet")); 
        b->setDirection(player->getTargetDirection());
        bullet_container.push_back(b);
    }                                                                                                                                                                                                                                                                        

    player->update();

    for (Bullet *b : bullet_container) {
        b->update();
    }

}