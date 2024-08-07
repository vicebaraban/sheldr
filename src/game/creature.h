#ifndef CREATURE_H_
#define CREATURE_H_

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <utility>
#include <vector>
#include "../engine/sprite/sprite_group.h"
#include "../engine/sprite/sprite.h"


class Creature {
public:

    Creature(sf::Vector2f pos) {
        position = pos;
        dx = 0;
        dy = 0;
        speedX = 0.2;
        speedY = 0.2;
    }

    sheldr::Sprite getSprite();

    void setSpriteTexture(sf::Texture*);

    sf::Vector2f getPosition();

    void move(sf::Vector2f);
    void moveX(float);
    void moveY(float);

    void setDirectionX(int);
    void setDirectionY(int);

    void update();


private:

    sf::Vector2f position;
    int dx;
    int dy;
    float speedX;
    float speedY;


    std::vector<sheldr::SpriteGroup> associated_sprite_groups;
    sheldr::Sprite sprite;

    void inputScan();
    
};


#endif  // CREATURE_H_
