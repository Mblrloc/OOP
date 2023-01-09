#include <cstdio>
#include <iostream>
using namespace std;

void check(int n);

int main() {
    int n;
    cin >> n;
    check(n);
}

void check(int n) {
    if (n % 10 == 0)
        printf("true\n");
    else
        printf("false\n");
}