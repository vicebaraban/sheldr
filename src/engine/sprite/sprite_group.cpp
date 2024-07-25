#include "sprite_group.h"


int sheldr::SpriteGroup::next_id = 0;


bool sheldr::SpriteGroup::has(const sheldr::Sprite& sprite) {
    auto it = std::find(storage.begin(), storage.end(), sprite);
    return it != storage.end();
}


void sheldr::SpriteGroup::add(const sheldr::Sprite& sprite) {
    if (!has(sprite)) {
        sprite.add(*this);
        storage.push_back(sprite);
    }
}

void sheldr::SpriteGroup::remove(const sheldr::Sprite& sprite) {
    auto it = std::find(storage.begin(), storage.end(), sprite);
    sprite.remove(*this);
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

bool sheldr::SpriteGroup::operator==(const SpriteGroup& other) const {
    return this->id == other.id;
}

bool sheldr::SpriteGroup::operator!=(const SpriteGroup& other) const {
    return !(*this == other);
}
