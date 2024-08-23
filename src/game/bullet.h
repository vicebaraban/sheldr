#ifndef BULLET_H_
#define BULLET_H_

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <utility>
#include <vector>
#include "../engine/sprite/sprite_group.h"
#include "../engine/sprite/sprite.h"
#include "creature.h"



class Bullet: public Creature {
public:

    Bullet();

    void update();

    void setDirection(sf::Vector2f);

    RectangleCollider &getCollider();

private:

    sf::Vector2f size;

    void initVariables();
    void initCollider();

    RectangleCollider *collider;
    
};


#endif  // BULLET_H_
