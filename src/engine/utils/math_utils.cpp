#include "math_utils.h"


sf::Vector2f calculateDirection(sf::Vector2f v1, sf::Vector2f v2) {
    float x = v2.x - v1.x;
    float y = v2.y - v1.y;
    float z = std::sqrt(x * x + y * y);
    float dx = x / z;
    float dy = y / z;
    return sf::Vector2f(dx, dy);
}

bool rectInRect(float x1_1, float y1_1, float x2_1, float y2_1, 
                float x1_2, float y1_2, float x2_2, float y2_2) {

    bool r = (x1_2 <= x1_1 && x1_1 <= x2_2) && (y1_2 <= y1_1 && y1_1 <= y2_2) || 
             (x1_2 <= x2_1 && x2_1 <= x2_2) && (y1_2 <= y2_1 && y2_1 <= y2_2) || 
             (x1_1 <= x1_2 && x1_2 <= x2_1) && (y1_1 <= y1_2 && y1_2 <= y2_1) || 
             (x1_1 <= x2_2 && x2_2 <= x2_1) && (y1_1 <= y2_2 && y2_2 <= y2_1);    

    return r;

}

bool circleInCircle(sf::Vector2f pos1, sf::Vector2f pos2, float r1, float r2) {
    
    return (pos2.x - pos1.x) * (pos2.x - pos1.x) + 
           (pos2.y - pos1.y) * (pos2.y - pos1.y) < 
           (r1 + r2) * (r1 + r2);
}

bool circleInRect(float x, float y, float r, float x1, float y1, float x2, float y2) {
    bool t = false;
    return false;
}

float hypotenuse(float x, float y) {
    return sqrt(x * x + y * y);
}