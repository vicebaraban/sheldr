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
#include "../engine/values.h"



class Bullet: public Creature {
public:

    Bullet(): Creature() {
        speed_x = 100.f * (1.f / FPS);
        speed_y = 100.f * (1.f / FPS);
        dx = 0.f;
        dy = 0.f;
    }

    void update();

    void setDirection(sf::Vector2f);
    
};


#endif  // BULLET_H_
