#include "sprite.h"


std::vector<sheldr::SpriteGroup> sheldr::Sprite::groups() {
    return included;
}

const void sheldr::Sprite::add(const sheldr::SpriteGroup group) const {
    included.push_back(group);
}

const void sheldr::Sprite::remove(const sheldr::SpriteGroup& group) const {
    auto it = std::find(included.begin(), included.end(), group);
    included.erase(it);
}

int sheldr::Sprite::next_id = 0;

int sheldr::Sprite::getId() const {
    return id;
}

bool sheldr::Sprite::operator==(const Sprite& other) const {
    return this->id == other.id;
}

bool sheldr::Sprite::operator!=(const Sprite& other) const {
    return !(*this == other);
}

void sheldr::Sprite::update() {
    
}

void sheldr::Sprite::kill() {
    for (int i = 0; i < included.size(); i++) {
        included[i].remove(*this);
    }
    delete this;
}