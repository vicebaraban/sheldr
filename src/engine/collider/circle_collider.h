#ifndef CIRCLE_COLLIDER_H_
#define CIRCLE_COLLIDER_H_


#include <SFML/Graphics.hpp>
#include "collider.h"
#include "../utils/math_utils.h"


class CircleCollider: Collider {
public:

    CircleCollider();

    float getRadius();

    void settings(sf::Vector2f, float);

    void update(sf::Vector2f);

    bool isCollide(Collider &);
    bool isCollide(RectangleCollider &);
    bool isCollide(CircleCollider &);

private:

    float radius;
    float diameter;
    sf::Vector2f center_point;

    float width;
    float height;
    
};


#endif  // CIRCLE_COLLIDER_H_
