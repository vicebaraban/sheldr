#ifndef SPRITE_H_
#define SPRITE_H_

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>

namespace sheldr {

    class Sprite: public sf::Sprite {

    public:
        Sprite(sf::Texture& texture): sf::Sprite(texture) {

        }

        void update();
        void add();
        void remove();
        void kill();
        void groups();

    private:

    };


}

#endif  // SPRITE_H_