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

    Creature();

    sheldr::Sprite &getSprite();

    void setSpriteTexture(sf::Texture*);

    sf::Vector2f getPosition();

    void setPosition(sf::Vector2f);

    void move(sf::Vector2f);
    void moveX(float);
    void moveY(float);

    void setDirectionX(float);
    void setDirectionY(float);

    void update();


protected:

    sf::Vector2f position;
    float dx;
    float dy;
    float speed_x;
    float speed_y;


    std::vector<sheldr::SpriteGroup> associated_sprite_groups;
    sheldr::Sprite sprite;

private:

    void initVariables();
    
};


#endif  // CREATURE_H_
