#include "playing_state.h"
#include <SFML/Window/Keyboard.hpp>
#include <iostream>


PlayingState::PlayingState(StateData* state_data): State(state_data) {
    this->initPlayer();
    this->initHouse();
    this->shoot_timer = new sf::Clock();
    this->shoot_cooldown = sf::seconds(1.f);
    this->shoot_cooldown_dt = sf::seconds(0.f);
    this->flag = false;
}

PlayingState::~PlayingState() {}

void PlayingState::initPlayer() {
    this->player = new Player();
    this->player->setSpriteTexture(sheldr::TextureManager::getTexture("car"));
    this->player->setPosition(sf::Vector2f(30.f, 30.f));
}

void PlayingState::initHouse() {
    this->house = new Building();
    this->house->setPosition(sf::Vector2f(120.f, 120.f));
    this->house->setSpriteTexture(sheldr::TextureManager::getTexture("house"));
    this->house->setSpriteScale(sf::Vector2f(5.f, 5.f));
}

void PlayingState::render() {
    auto &window = sheldr::WindowManager::get();
    window.draw(house->getSprite());
    window.draw(player->getSprite());
    for (Bullet *b : bullet_container) {
        window.draw(b->getSprite());
    }
}

void PlayingState::update(const float &dt) {
    this->shoot_cooldown_dt += this->shoot_timer->restart();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && 
    this->shoot_cooldown_dt >= this->shoot_cooldown) {
        this->shoot_cooldown_dt = sf::seconds(0.f);
        Bullet *b = new Bullet();
        b->setPosition(this->player->getPosition());
        b->setSpriteTexture(sheldr::TextureManager::getTexture("bullet")); 
        b->setDirection(this->player->getTargetDirection());
        this->bullet_container.push_back(b);
    }
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab)) {
        this->player->setSpeedX(6.f);
        this->player->setSpeedY(6.f);
    }
    else {
        this->player->setSpeedX(2.f);
        this->player->setSpeedY(2.f);
    }
    
    this->player->update();

    this->house->update();


    // if (this->player->getSprite().getGlobalBounds().intersects(this->house->getSprite().getGlobalBounds())) {
    //     std::cout << "1\n";
    // }

    // std::cout << player->getCollider().getRectCoords().first.x << " "
    //           << player->getCollider().getRectCoords().first.y << " "
    //           << player->getCollider().getRectCoords().second.x << " "
    //           << player->getCollider().getRectCoords().second.y << "\n";
    // std::cout << house->getCollider().getRectCoords().first.x << "\n";
    
    // if (player->getCollider().isCollide(house->getCollider())) {
    //     std::cout << "1\n";
    // }

    for (auto i = bullet_container.begin(); i != bullet_container.end();) {
        Bullet *b = *i;
        b->update();
        if (b->getCollider().isCollide(this->house->getCollider())) {
            std::cout << "Explosive!\n";
            bullet_container.erase(i);
            delete b;
        }
        else {
            i++;
        }
    }

}