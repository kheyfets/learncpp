#include <iostream>

void swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

int main() {
    int x = 5;
    int y = 7;
    swap(x, y);
    std::cout << "x = " << x << " and y = " << y << std::endl;
}
