#include <cmath>
#include "point.h"

struct Circle {

private:
    Point center;
    float radius;
    const float PI = 3.14;

public:  
    Circle() {
        center = Point{0, 0};
        radius = 1;
    }

    Circle(const Point& acenter, float aradius) {
        center = acenter;
        radius = aradius;
    }

    Circle(const Circle& circle) {
        center = circle.center;
        radius = circle.radius;
    }

    Point getCenter() const;
    float getRadius() const;
    void setCenter(const Point& p);
    void setRadius(float r);
    float getArea();
    float getDistance(const Point p) const;
    bool isColliding(const Circle& c) const;
    void move(const Point& p);
    void print() const;
};