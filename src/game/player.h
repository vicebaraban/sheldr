#ifndef PLAYER_H_
#define PLAYER_H_

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <cmath>
#include <utility>
#include <vector>
#include "../engine/sprite/sprite_group.h"
#include "../engine/sprite/sprite.h"
#include "creature.h"
#include "../engine/values.h"
#include "../engine/control/process_events_manager.h"
#include "../engine/utils/math_utils.h"
#include "bullet.h"



class Player: public Creature {
public:

    Player(): Creature() {

        speed_x = 30.f * (1.f / FPS);
        speed_y = 30.f * (1.f / FPS);
    }

    void update();

    sf::Vector2f getTargetDirection();

    void inputScan();


private:

    sf::Vector2f target_direction;

    void updateTargetDirection();

    // void shoot();
    
};


#endif  // PLAYER_H_
