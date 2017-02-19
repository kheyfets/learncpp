#include <iostream>
#include "constants.h"

double getInitialHeight() {
    std::cout << "Enter the initial height of the tower in meters: ";
    int height;
    std::cin >> height;
    return height;
}

double getHeightAt(double sec, double init) {
    return init - (myConstants::gravity * sec * sec / 2);
}

int main() {
    double height = getInitialHeight();
    
    for (int i = 0; i < 6; i++) {
        double currentHeight = getHeightAt(i, height);
        
        std::cout << "At " << i << " seconds, the ball is ";
        
        if (currentHeight <= 0) {
            std::cout << "on the ground.";
        } else {
            std::cout << "at height: " << currentHeight;
        }

        std::cout << std::endl;
    }
}
