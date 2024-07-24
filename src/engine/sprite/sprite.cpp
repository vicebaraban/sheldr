#include "sprite.h"


// std::vector<sheldr::SpriteGroup> sheldr::Sprite::groups() {
//     return included;
// }

// void sheldr::Sprite::add(sheldr::SpriteGroup &group) {
//     included.push_back(*group);
// }

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