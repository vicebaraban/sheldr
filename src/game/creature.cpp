#include "creature.h"


void Creature::setSpriteTexture(sf::Texture* texture) {
    sprite.setTexture(*texture);
}

sheldr::Sprite Creature::getSprite() {
    return sprite;
}
