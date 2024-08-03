#ifndef CREATURE_H_
#define CREATURE_H_

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <utility>
#include <vector>
#include "../engine/sprite/sprite_group.h"
#include "../engine/sprite/sprite.h"


class Creature {
public:

    Creature(std::pair<int, int> pos) {
        position = pos;
    }

    sheldr::Sprite getSprite();

    void setSpriteTexture(sf::Texture*);


private:

    std::vector<sheldr::SpriteGroup> associated_sprite_groups;
    std::pair<int, int> position;
    sheldr::Sprite sprite;
    
};


#endif  // CREATURE_H_
