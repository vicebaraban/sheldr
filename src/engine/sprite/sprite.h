#ifndef SPRITE_H_
#define SPRITE_H_

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <vector>


namespace sheldr {

    class SpriteGroup;

    class Sprite: public sf::Sprite {

    public:

        Sprite(const sf::Texture* texture): sf::Sprite(*texture) {
            id = next_id;
            next_id++;
        }

        std::vector<SpriteGroup> groups();

        const void add(const SpriteGroup) const;

        const void remove(const SpriteGroup&) const;

        bool operator==(const Sprite& other) const;
        bool operator!=(const Sprite& other) const;

        void update();

        void kill();

        int getId() const;


    private:

        static int next_id;

        int id;

        mutable std::vector<SpriteGroup> included;

    };

}

#include "sprite_group.h"

#endif  // SPRITE_H_