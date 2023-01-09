#include <cstdio>
#include <iostream>
using namespace std;

namespace foo {
    int a = 5;

    int square(int x) {
        return x * x;
    }
}

int main() {
    using namespace foo;
    a = square(a);
    printf("%d\n", foo::a);
}
