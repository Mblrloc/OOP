#include <cmath>
#include "circle.h"
#include <iostream>


Point Circle::getCenter() const{
    return center;
}

float Circle::getRadius() const{
    return radius;
}

void Circle::setCenter(const Point& p) {
    center = p;
}

void Circle::setRadius(float r) {
    if (r >= 0)
        radius = r;
    else
        radius = 0;
}

float Circle::getArea() {
    return radius * radius * PI;
}

float Circle::getDistance(const Point p) const {
    float dx, dy, d;
    dx = center.x - p.x;
    dy = center.y - p.y;
    d = sqrt(dx * dx + dy * dy);
    if (d <= radius)
        return 0;
    else
        return d - radius; 
}

bool Circle::isColliding(const Circle& c) const {
    if (getDistance(c.getCenter()) <= c.getRadius()) {
        return true;
    }
    return false;
}

void Circle::move(const Point& p) {
    center.x += p.x;
    center.y += p.y;
}

void Circle::print() const{
    cout << "Circle: x = " << center.x << " y = " << center.y << " r = " << radius << endl;
}