#include "student-1.h"
#include <iostream>
#include <windows.h>

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"
#define RESET   "\033[0m"

int main() {
    system("cls");
    int choice;
    do {
        std::cout << CYAN "\n=== Student Management System ===\n" RESET;
        std::cout << GREEN "1. Add Student\n" RESET;
        std::cout << GREEN "2. Display All Students\n" RESET;
        std::cout << GREEN "3. Search Student\n" RESET;
        std::cout << YELLOW "4. Update Student\n" RESET;
        std::cout << RED "5. Delete Student\n" RESET;
        std::cout << RED "6. Exit\n" RESET;
        std::cout << "Choice: "; std::cin >> choice;

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: updateStudent(); break;
            case 5: deleteStudent(); break;
            case 6: std::cout << GREEN "Goodbye!\n" RESET; break;
            default: std::cout << RED "Invalid choice.\n" RESET;
        }
    } while (choice != 6);

    return 0;
}