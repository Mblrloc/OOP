#include "circle.cpp"

main() {
    Circle c = Circle();
    Circle c2 = Circle({2, 2}, 2);
    Circle c3 = c2;
    c.print();
    c2.print();
    c3.print();
    cout << c2.isColliding(c3) << endl;
    c3.move({100, 100});
    cout << c2.isColliding(c3) << endl;
    c.print();
    c2.print();
    c3.print();
} 