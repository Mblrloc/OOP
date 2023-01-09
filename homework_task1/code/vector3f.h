#pragma once
#include <cmath>
#include <iostream>
#include <assert.h>
struct Vector3F {
    float x;
    float y;
    float z;
};

Vector3F operator+(const Vector3F& a, const Vector3F& b) {
    Vector3F result = {a.x + b.x, a.y + b.y, a.z + b.z};
    return result;
}

Vector3F operator-(const Vector3F& a, const Vector3F& b) {
    Vector3F result = {a.x - b.x, a.y - b.y, a.z - b.z};
    return result;
}

Vector3F operator*(const float a, const Vector3F& b) {
    Vector3F result = {b.x * a, b.y * a, b.z * a};
    return result;
}

Vector3F operator*(const Vector3F& b, const float a) {
    Vector3F result = {b.x * a, b.y * a, b.z * a};
    return result;
}

float operator*(const Vector3F& a, const Vector3F& b) {
    float result = a.x * b.x + a.y * b.y + a.z * b.z;
    return result;
}


Vector3F operator/(const Vector3F& a, const float b) {
    assert(b != 0);
    Vector3F result = {a.x / b, a.y / b, a.z / b};
    return result;
}

Vector3F& operator+=(Vector3F &a, const Vector3F &b) {
    a.x += b.x;
    a.y += b.y;
    a.z += b.z;
    return a;
}

Vector3F& operator-=(Vector3F &a, const Vector3F &b) {
    a.x -= b.x;
    a.y -= b.y;
    a.z -= b.z;
    return a;
}

Vector3F& operator*=(Vector3F &a, float b) {
    a.x *= b;
    a.y *= b;
    a.z *= b;
    return a;
}

Vector3F& operator/=(Vector3F &a, float b) {
    assert(b != 0);
    a.x /= b;
    a.y /= b;
    a.z /= b;
    return a;
}

// Унарный оператор -
// То есть если z - комплексное число x + iy, то -z = - x - iy
Vector3F operator-(const Vector3F& a) {
    Vector3F result;
    result.x = - a.x;
    result.y = - a.y;
    result.z = - a.z;
    return result;
}

// Унарный оператор +
// Ничего не меняет
Vector3F operator+(const Vector3F& a) {
    Vector3F result = a;
    return result;
}

bool operator==(const Vector3F& a, const Vector3F b) {
    return (a.x == b.x && a.y == b.y && a.z == b.z);
}

bool operator!=(const Vector3F& a, const Vector3F b) {
    return !(a.x == b.x && a.y == b.y && a.z == b.z);
}


// Перегружаем оператор<< между типами 
// std::ostream (такой тип имеет std::cout) и Complex
// Обратите внимание, что мы возвращаем ссылку на ostream
// Таким образом результатом выражения  cout << a  будет cout
// Поэтому можно делать так: cout << a << b << c ...
std::ostream& operator<<(std::ostream& out, const Vector3F& a) {
    out << "(" << a.x << ", " << a.y << ", " << a.z << ")";
    return out;
}

std::istream& operator>>(std::istream& in, Vector3F& a) {
    in >> a.x >> a.y >> a.z;
    return in;
}

float norm(const Vector3F& a) {
    return sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
}

float squared_norm(const Vector3F& a) { 
    return (a.x * a.x + a.y * a.y + a.z * a.z);
}

void normalize(Vector3F& a) {
    float normm = norm(a);
    a.x /= normm;
    a.y /= normm;
    a.z /= normm;
}