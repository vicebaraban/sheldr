#ifndef MATH_UTILS_H_
#define MATH_UTILS_H_

#include <SFML/System/Vector2.hpp>
#include <math.h>
#include <SFML/Graphics.hpp>

// v1 - main, v2 - target
// -> (float dx, float dy) dx, dy in [-1, 1]
sf::Vector2f calculateDirection(sf::Vector2f, sf::Vector2f);

bool rectInRect(float, float, float, float, 
                float, float, float, float);

bool circleInCircle(sf::Vector2f, sf::Vector2f, float, float);

bool circleInRect(float, float, float,
                  float, float, float, float);

float hypotenuse(float, float);

#endif  // MATH_UTILS_H_