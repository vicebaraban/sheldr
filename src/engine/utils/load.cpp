#include "load.h"


void loadImages() {
    sheldr::TextureManager::loadTexture("test_texture", "assets/square.png");
    sheldr::TextureManager::loadTexture("bullet", "assets/bullet.png");
    sheldr::TextureManager::loadTexture("house", "assets/house.png");
    sheldr::TextureManager::loadTexture("car", "assets/car.png");
}