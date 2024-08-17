#ifndef COLLIDER_H_
#define COLLIDER_H_


#include <SFML/Graphics.hpp>


class RectangleCollider;


class Collider {
public:

    Collider();

    void setCenterPosition(sf::Vector2f);
    sf::Vector2f getCenterPosition();

    bool isCollide(Collider &);
    bool isCollide(RectangleCollider &);

protected:

    sf::Vector2f center_point;

private:
    

};


#include "rectangle_collider.h"


#endif  // COLLIDER_H_
