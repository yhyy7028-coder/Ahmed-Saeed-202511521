#include "student.h"

void addStudent(vector<Student>& students) {
    Student s;
    cout << "\n--- Add Student ---\n";
    cout << "Enter ID: ";     cin >> s.id;
    cout << "Enter Name: ";   cin.ignore(); getline(cin, s.name);
    cout << "Enter Age: ";    cin >> s.age;
    cout << "Enter Course: "; cin.ignore(); getline(cin, s.course);
    students.push_back(s);
    cout << "Student added successfully!\n";
}

void displayStudents(const vector<Student>& students) {
    cout << "\n--- All Students ---\n";
    if (students.empty()) {
        cout << "No students found.\n";
        return;
    }
    for (const Student& s : students) {
        cout << "ID: " << s.id
             << " | Name: " << s.name
             << " | Age: " << s.age
             << " | Course: " << s.course << "\n";
    }
}

void searchStudent(const vector<Student>& students) {
    int id;
    cout << "\nEnter Student ID to search: ";
    cin >> id;
    for (const Student& s : students) {
        if (s.id == id) {
            cout << "Found -> Name: " << s.name
                 << ", Age: " << s.age
                 << ", Course: " << s.course << "\n";
            return;
        }
    }
    cout << "Student not found.\n";
}

void updateStudent(vector<Student>& students) {
    int id;
    cout << "\nEnter Student ID to update: ";
    cin >> id;
    for (Student& s : students) {
        if (s.id == id) {
            cout << "Enter new Name: ";   cin.ignore(); getline(cin, s.name);
            cout << "Enter new Age: ";    cin >> s.age;
            cout << "Enter new Course: "; cin.ignore(); getline(cin, s.course);
            cout << "Student updated successfully!\n";
            return;
        }
    }
    cout << "Student not found.\n";
}

void deleteStudent(vector<Student>& students) {
    int id;
    cout << "\nEnter Student ID to delete: ";
    cin >> id;
    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->id == id) {
            students.erase(it);
            cout << "Student deleted successfully!\n";
            return;
        }
    }
    cout << "Student not found.\n";
}