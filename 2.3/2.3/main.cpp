#include <iostream>

double readNumber() {
    std::cout << "Enter a double: ";
    double num;
    std::cin >> num;
    return num;
}

char readOperator() {
    std::cout << "Enter an operator: ";
    char oper;
    std::cin >> oper;
    return oper;
}

void writeAnswer(double firstNum, double secondNum, char oper) {
    double res;
    
    if (oper == '*') {
        res = firstNum * secondNum;
    } else if (oper == '/') {
        res = firstNum / secondNum;
    } else if (oper == '-') {
        res = firstNum - secondNum;
    } else if (oper == '+') {
        res = firstNum + secondNum;
    }
    
    std::cout << firstNum << " " << oper << " " << secondNum << " is " << res << std::endl;
}

int main() {
    double firstNum = readNumber();
    double secondNum = readNumber();
    char oper = readOperator();
    writeAnswer(firstNum, secondNum, oper);
}
