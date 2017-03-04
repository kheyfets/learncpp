#include <iostream>

void printString(const char *str) {
    while (*str != 0) {
        std::cout << *str;
        str++;
    }
    
    std::cout << std::endl;
}

int main() {
    printString("My name is Phillip.");
}
