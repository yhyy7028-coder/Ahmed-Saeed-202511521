#include "student.h"

int main() {
    vector<Student> students;
    int choice;

    do {
        cout << "\n====== Student Management System ======\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student by ID\n";
        cout << "4. Update Student\n";
        cout << "5. Delete Student\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(students);      break;
            case 2: displayStudents(students); break;
            case 3: searchStudent(students);   break;
            case 4: updateStudent(students);   break;
            case 5: deleteStudent(students);   break;
            case 6: cout << "Goodbye!\n";      break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 6);

    return 0;
}