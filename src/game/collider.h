#ifndef COLLIDER_H_
#define COLLIDER_H_


#include <SFML/Graphics.hpp>


class Collider {
public:

    Collider();

    void setCenterPosition(sf::Vector2f);

protected:

    sf::Vector2f center;

private:
    

};

class RectangleCollider: Collider {
public:

    RectangleCollider();

};


#endif  // COLLIDER_H_
