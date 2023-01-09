#include <iostream>

struct Book {
    char title[100];
    int pages;
    float price;
};

bool isExpensive(const Book& b) {
    return (b.price > 1000);
}

void addPrice(Book& b, float p) {
    b.price += p;
}

main() {
    Book book = {"War and Peace", 12, 500};
    std::cout << isExpensive(book) << std::endl;
    addPrice(book, 600);
    std::cout << isExpensive(book) << std::endl;
}
