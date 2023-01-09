#include <iostream>

namespace myspace {
    void print_n_times(char str[], int n = 10) {
        for(int i1 = 0; i1 < n; i1++) {
            for(int i2 = 0; str[i2] != '\0'; i2++) {
                std::cout << str[i2];
            }
            std::cout << std::endl;
        }
    }
}

int main() {
    myspace::print_n_times("Hello!");
}