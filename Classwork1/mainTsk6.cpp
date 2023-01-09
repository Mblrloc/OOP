#include <cstdio>
#include <iostream>
using namespace std;

namespace bar {
    int a = 7;
}

int main() {
    using namespace bar;
    printf("%d\n", bar::a);
}
