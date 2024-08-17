#include "collider.h"


Collider::Collider() {};


void Collider::setCenterPosition(sf::Vector2f point) {
    this->center_point = point;
}

sf::Vector2f Collider::getCenterPosition() {
    return this->center_point;
}

bool Collider::isCollide(Collider &shape) {
    sf::Vector2f pos = shape.getCenterPosition();
    return this->center_point == pos;
}

bool Collider::isCollide(RectangleCollider &shape) {
    sf::Vector2f t_l_point = shape.getRectCoords().first;
    sf::Vector2f b_r_point = shape.getRectCoords().second;
    float _x = this->center_point.x;
    float _y = this->center_point.y;
    return (t_l_point.x <= _x <= b_r_point.x) && (t_l_point.y <= _y <= b_r_point.y);
}
