#ifndef RECTANGLE_COLLIDER_H_
#define RECTANGLE_COLLIDER_H_


#include <SFML/Graphics.hpp>
#include "collider.h"
#include "../utils/math_utils.h"


class RectangleCollider: Collider {
public:

    RectangleCollider();

    std::pair<sf::Vector2f, sf::Vector2f> getRectCoords();

    void settings(sf::Vector2f, sf::Vector2f);

    void update(sf::Vector2f);

    bool isCollide(Collider &);
    bool isCollide(RectangleCollider &);

private:

    sf::Vector2f top_left_point;
    sf::Vector2f bottom_right_point;
    sf::Vector2f center_point;

    float width;
    float height;
    
};


#endif  // RECTANGLE_COLLIDER_H_
