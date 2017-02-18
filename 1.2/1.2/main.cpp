int readNumber();
void writeAnswer(int answer);

int main() {
    int firstNum = readNumber();
    int secondNum = readNumber();
    writeAnswer(firstNum + secondNum);
}
