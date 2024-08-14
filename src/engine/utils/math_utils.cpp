#include "math_utils.h"
#include <SFML/System/Vector2.hpp>
#include <cmath>


sf::Vector2f calculateDirection(sf::Vector2f v1, sf::Vector2f v2) {
    float x = v2.x - v1.x;
    float y = v2.y - v1.y;
    float z = std::sqrt(x * x + y * y);
    float dx = x / z;
    float dy = y / z;
    return sf::Vector2f(dx, dy);
}