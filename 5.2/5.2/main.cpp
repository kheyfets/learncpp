#include <iostream>
#include <cstdlib>
#include <ctime>

int getGuess(int guessNumber) {
    int guess;
    std::cout << "Guess #" << guessNumber << ": ";
    std::cin >> guess;
    return guess;
}

int getRandomNumber(int min, int max) {
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

bool playAgain() {
    while (true) {
        char playAgain;
        std::cout << "Would you like to play again (y/n)? ";
        std::cin >> playAgain;
        if (playAgain == 'y') {
            return true;
        } else if (playAgain == 'n') {
            return false;
        }
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0)));
    rand();
    
    while (true) {
        std::cout << "Let's play a game. I'm thinking of a number. You have 7 tries to guess what it is." << std::endl;
        
        int goal = getRandomNumber(0, 100);
        int guessNumber = 1;
        
        while (true) {
            int guess = getGuess(guessNumber);
            guessNumber++;
        
            if (guess == goal) {
                std::cout << "Correct! You win!" << std::endl;
                break;
            } else if (guess > goal) {
                std::cout << "Your guess is too high." << std::endl;
            } else if (guess < goal) {
                std::cout << "Your guess is too low." << std::endl;
            }
        
            if (guessNumber > 7) {
                std::cout << "Sorry, you lose. The correct number was " << goal << "." << std::endl;
                break;
            }
        }
        
        if (!playAgain()) {
            break;
        }
    }
    
    std::cout << "Thank you for playing." << std::endl;
}
