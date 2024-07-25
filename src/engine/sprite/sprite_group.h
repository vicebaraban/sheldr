#ifndef SPRITE_GROUP_H_
#define SPRITE_GROUP_H_

#include <SFML/Graphics/Sprite.hpp>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>


namespace sheldr {

    class Sprite;

    class SpriteGroup {

    public:

        SpriteGroup() {
            id = next_id;
            next_id++;
        }
        
        std::vector<Sprite> sprites();

        void add(const Sprite&);

        void remove(const Sprite&);

        bool has(const Sprite&);

        void update();

        void clear();

        void empty();

        bool operator==(const SpriteGroup& other) const;
        bool operator!=(const SpriteGroup& other) const;

    private:

        static int next_id;

        int id;

        std::vector<Sprite> storage;

    };


}

#include "sprite.h"

#endif  // SPRITE_GROUP_H_