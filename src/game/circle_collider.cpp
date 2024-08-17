#include "circle_collider.h"
#include <iostream>


CircleCollider::CircleCollider(): Collider() {};


void CircleCollider::settings(sf::Vector2f pos, float width) {
    this->radius = width / 2.f;
    this->diameter = width;
    // float h = hypotenuse(radius, radius);
    this->center_point = pos + sf::Vector2f(radius, radius);
}

void CircleCollider::update(sf::Vector2f pos) {
    this->center_point = pos + sf::Vector2f(this->radius, this->radius);
}

float CircleCollider::getRadius() {
    return this->radius;
}

bool CircleCollider::isCollide(Collider &shape) {
    return circleInCircle(this->center_point, shape.getCenterPosition(), this->radius, 0.f);
}

bool CircleCollider::isCollide(CircleCollider &shape) {
    return circleInCircle(this->center_point, shape.getCenterPosition(),
     this->radius, shape.getRadius());
}

// bool CircleCollider::isCollide(RectangleCollider &shape) {
    
//     return rectInRect(this->top_left_point.x,
//                       this->top_left_point.y, 
//                       this->bottom_right_point.x,
//                       this->bottom_right_point.y,
//                       shape.getRectCoords().first.x,
//                       shape.getRectCoords().first.y,
//                       shape.getRectCoords().second.x,
//                       shape.getRectCoords().second.y
//                       );
// }
