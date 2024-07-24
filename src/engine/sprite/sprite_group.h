#ifndef SPRITE_GROUP_H_
#define SPRITE_GROUP_H_

#include <SFML/Graphics/Sprite.hpp>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "sprite.h"


namespace sheldr {

    class SpriteGroup {

    public:
        
        std::vector<Sprite> sprites();

        void add(const Sprite&);

        void remove(const Sprite&);

        bool has(const Sprite&);

        void update();

        void clear();

        void empty();

    private:

        std::vector<Sprite> storage;

    };


}

#endif  // SPRITE_GROUP_H_