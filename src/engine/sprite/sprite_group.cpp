#include "sprite_group.h"


bool sheldr::SpriteGroup::has(sheldr::Sprite sprite) {
    auto it = std::find(stoarge.begin(), stoarge.end(), sprite);
    if (it != stoarge.end()) {
        return true;
    }
    return false;
}


void sheldr::SpriteGroup::add(sheldr::Sprite sprite) {

}