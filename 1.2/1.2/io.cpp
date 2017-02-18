#include <iostream>

int readNumber() {
    std::cout << "Enter a number: ";
    int ui;
    std::cin >> ui;
    return ui;
}

void writeAnswer(int answer) {
    std::cout << "The answer is: " << answer << std::endl;
}
