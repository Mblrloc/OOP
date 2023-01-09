#include <iostream>
#include <iomanip>
#include <cmath>
using std::cout;
using std::endl;


struct Point 
{
    float x, y;
};

void pointPrint(Point a)
{
    cout << std::setprecision(2) << "(" << a.x << ", " << a.y << ")" << endl;
}

Point operator+(Point a, Point b)
{
    Point result = {a.x + b.x, a.y + b.y};
    return result;
}

float pointNorm(Point a)
{
    return std::sqrt(a.x * a.x + a.y * a.y);
}

Point operator*(Point a, float k)
{
    Point result = {k * a.x, k * a.y};
    return result;
}

void pointNormalize(Point& a)
{
    float norm = pointNorm(a);
    a.x /= norm;
    a.y /= norm;
}
