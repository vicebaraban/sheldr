#ifndef BUILDING_H_
#define BUILDING_H_

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <utility>
#include <vector>
#include "../engine/sprite/sprite_group.h"
#include "../engine/sprite/sprite.h"
#include "creature.h"
#include "../engine/collider/rectangle_collider.h"



class Building: public Creature {
public:

    Building();

    void update();

    RectangleCollider &getCollider();

private:

    sf::Vector2f size;
    
    void initVariables();
    void initCollider();

    RectangleCollider *collider;
    
};


#endif  // BUILDING_H_
