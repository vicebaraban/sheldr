#include "sprite_group.h"


bool sheldr::SpriteGroup::has(const sheldr::Sprite& sprite) {
    auto it = std::find(storage.begin(), storage.end(), sprite);
    return it != storage.end();
}


void sheldr::SpriteGroup::add(const sheldr::Sprite& sprite) {
    if (!has(sprite)) {
        // sprite.add(this);
        storage.push_back(sprite);
    }
}

void sheldr::SpriteGroup::remove(const sheldr::Sprite& sprite) {
    auto it = std::find(storage.begin(), storage.end(), sprite);
    storage.erase(it);
}

void sheldr::SpriteGroup::empty() {
    storage.clear();
}

void sheldr::SpriteGroup::update() {
    for (Sprite& sprite : storage) {
        sprite.update();
    }
}
