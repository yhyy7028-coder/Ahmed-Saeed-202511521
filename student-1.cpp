#include "student.h"
#include <iostream>
#include <algorithm>

std::vector<Student> students;

void addStudent() {
    int id, age;
    std::string name, course;

    std::cout << "Enter ID: "; std::cin >> id;
    std::cout << "Enter Name: "; std::cin.ignore(); std::getline(std::cin, name);
    std::cout << "Enter Age: "; std::cin >> age;
    std::cout << "Enter Course: "; std::cin.ignore(); std::getline(std::cin, course);

    Student s(id, name, age, course);
    students.push_back(s);
    std::cout << "Student added.\n";
}

void displayStudents() {
    if (students.empty()) {
        std::cout << "No students found.\n";
        return;
    }
    for (Student s : students) {
        s.display();
    }
}

void searchStudent() {
    int id;
    std::cout << "Enter ID: "; std::cin >> id;
    for (Student s : students) {
        if (s.getId() == id) {
            s.display();
            return;
        }
    }
    std::cout << "Student not found.\n";
}

void updateStudent() {
    int id;
    std::cout << "Enter ID to update: "; std::cin >> id;
    for (Student& s : students) {
        if (s.getId() == id) {
            std::string name, course;
            int age;
            std::cout << "Enter new Name: "; std::cin.ignore(); std::getline(std::cin, name);
            std::cout << "Enter new Age: "; std::cin >> age;
            std::cout << "Enter new Course: "; std::cin.ignore(); std::getline(std::cin, course);
            s.setName(name);
            s.setAge(age);
            s.setCourse(course);
            std::cout << "Student updated.\n";
            return;
        }
    }
    std::cout << "Student not found.\n";
}

void deleteStudent() {
    int id;
    std::cout << "Enter ID to delete: "; std::cin >> id;
    auto it = std::remove_if(students.begin(), students.end(),
        [id](Student s) { return s.getId() == id; });
    if (it != students.end()) {
        students.erase(it, students.end());
        std::cout << "Student deleted.\n";
    } else {
        std::cout << "Student not found.\n";
    }
}