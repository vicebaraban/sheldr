#ifndef WALL_H_
#define WALL_H_

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <utility>
#include <vector>
#include "../engine/sprite/sprite_group.h"
#include "../engine/sprite/sprite.h"
#include "creature.h"
#include "../engine/values.h"



class Wall: public Creature {
public:

    Wall();

    void update();

    void setDirection(sf::Vector2f);

private:
    void initVariables();
    
};


#endif  // WALL_H_
