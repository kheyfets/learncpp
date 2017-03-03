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
    double init = getInitialHeight();
    double height = init;
    
    int time = 0;
    
    do {
        height = getHeightAt(time, init);
        
        std::cout << "At " << time << " seconds, the ball is ";
        
        if (height <= 0) {
            std::cout << "on the ground.";
        } else {
            std::cout << "at height: " << height;
        }
        
        std::cout << std::endl;
        
        time++;
    } while (height > 0);
}
