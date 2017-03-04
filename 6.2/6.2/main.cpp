#include <iostream>
#include <string>
#include <utility>

struct Student {
    std::string name;
    int grade;
};

void sortNames(Student *students, int length) {
    for (int i = 0; i < length; i++) {
        int largest = i;
        
        for (int j = i + 1; j < length; j++) {
            if (students[j].grade > students[largest].grade) {
                largest = j;
            }
        }

        std::swap(students[i], students[largest]);
    }
}

int main() {
    int numStudents = 0;
    std::cout << "How many students do you want to enter? ";
    std::cin >> numStudents;
    
    Student *students = new Student[numStudents];
    
    for (int i = 0; i < numStudents; i++) {
        std::cout << "Enter name #" << i + 1 << ": ";
        std::cin >> students[i].name;
        
        std::cout << "Enter grade #" << i + 1 << ": ";
        std::cin >> students[i].grade;
    }
    
    sortNames(students, numStudents);
    
    for (int i = 0; i < numStudents; i++) {
        std::cout << students[i].name << " got a grade of " << students[i].grade << std::endl;
    }
}
