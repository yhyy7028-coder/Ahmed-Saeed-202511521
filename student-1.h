#pragma once
#include <string>
#include <vector>

class Student {
private:
    int id;
    std::string name;
    int age;
    std::string course;

public:
    Student() : id(0), age(0) {}
    Student(int id, std::string name, int age, std::string course)
        : id(id), name(name), age(age), course(course) {}

    int getId() const { return id; }
    std::string getName() const { return name; }
    int getAge() const { return age; }
    std::string getCourse() const { return course; }

    void setId(int i) { id = i; }
    void setName(std::string n) { name = n; }
    void setAge(int a) { age = a; }
    void setCourse(std::string c) { course = c; }

    void display() const {
        std::cout << "ID: " << id
                  << " | Name: " << name
                  << " | Age: " << age
                  << " | Course: " << course << "\n";
    }
};

extern std::vector<Student> students;

void addStudent();
void displayStudents();
void searchStudent();
void updateStudent();
void deleteStudent();