#include <iostream>

void cubeR(int& a) {
    a = a * a * a;
}

int cubeV(int a) {
    return a * a * a;
}

int main() {
    int a = 3;
    std::cout << a << "^3 = ";
    cubeR(a);
    std::cout << a << std::endl;
}