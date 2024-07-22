#ifndef SPRITE_GROUP_H_
#define SPRITE_GROUP_H_

#include "sprite.h"
#include <SFML/Graphics/Sprite.hpp>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "sprite.h"


namespace sheldr {

    class SpriteGroup {

    public:
        
        std::vector<Sprite> sprites();

        void add(Sprite);

        void remove(Sprite);

        bool has(Sprite);

        void update();

        void clear();

        void empty();

    private:

        std::vector<Sprite> stoarge;
        
    };


}

#endif  // SPRITE_GROUP_H_