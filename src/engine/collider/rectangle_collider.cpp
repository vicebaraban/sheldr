#include "rectangle_collider.h"


RectangleCollider::RectangleCollider(): Collider() {};


void RectangleCollider::settings(sf::Vector2f pos, sf::Vector2f wh) {
    this->top_left_point = pos;
    this->bottom_right_point = pos + wh; 
    this->center_point = pos + sf::Vector2f(wh.x / 2, wh.y / 2);
    this->width = wh.x;
    this->height = wh.y;
}

void RectangleCollider::update(sf::Vector2f pos) {
    // std::cout << "1\n";
    this->top_left_point = pos;
    this->bottom_right_point = pos + sf::Vector2f(this->width, this->height);
    this->center_point = pos + sf::Vector2f(this->width / 2, this->height / 2);
}

std::pair<sf::Vector2f, sf::Vector2f> RectangleCollider::getRectCoords() {
    return std::pair(top_left_point, bottom_right_point);
}

bool RectangleCollider::isCollide(Collider &shape) {
    sf::Vector2f pos = shape.getCenterPosition();
    return (this->top_left_point.x <= pos.x <= this->bottom_right_point.x) &&
     (this->top_left_point.y <= pos.y <= this->bottom_right_point.y);
}

bool RectangleCollider::isCollide(RectangleCollider &shape) {
    
    return rectInRect(this->top_left_point.x,
                      this->top_left_point.y, 
                      this->bottom_right_point.x,
                      this->bottom_right_point.y,
                      shape.getRectCoords().first.x,
                      shape.getRectCoords().first.y,
                      shape.getRectCoords().second.x,
                      shape.getRectCoords().second.y
                      );
}
