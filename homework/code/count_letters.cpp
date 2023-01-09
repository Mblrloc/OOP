#include <iostream>

void count_letters(char str[], int& n_letters, int& n_digits, int& n_other) {
    for(int i1 = 0; str[i1] != '\0'; i1++) {
        if (('A' <= str[i1] && str[i1] <= 'Z') || ('a' <= str[i1] && str[i1] <= 'z')) {
            n_letters++;
        } else if ('0' <= str[i1] && str[i1] <= '9') {
            n_digits++;
        } else {
            n_other++;
        }
    }
}

int main() {
    int letters = 0, digits = 0, other = 0;
    count_letters("AbcdEfz0123456789+_+_+_+", letters, digits, other);
    std::cout << "n_letters = " << letters << std::endl;
    std::cout << "n_digits = " << digits << std::endl;
    std::cout << "n_other = " << other << std::endl;
}