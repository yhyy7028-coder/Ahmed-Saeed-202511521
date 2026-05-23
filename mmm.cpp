#include <iostream>
#include <string>
using namespace std;

void calculate_results(float marks[], float &total, float &average, string &status) {
   total = 0;
   for (int i = 0; i < 3; i++) {
       total += marks[i];
   }
   average = total / 3;
   status = (average >= 50) ? "PASSED" : "FAILED";
}

void display_result(string name, float marks[], float total, float average, string status) {
   cout << "\n====" << endl;
   cout << "Student Name : " << name << endl;
   cout << "Subject 1    : " << marks[0] << endl;
   cout << "Subject 2    : " << marks[1] << endl;
   cout << "Subject 3    : " << marks[2] << endl;
   cout << "Total        : " << total << endl;
   cout << "Average      : " << average << endl;
   cout << "Result       : " << status << endl;
   cout << "====" << endl;
}

float get_marks(int subject_num) {
   float mark;
   while (true) {
       cout << "Enter marks for Subject " << subject_num << ": ";
       cin >> mark;
       if (mark >= 0 && mark <= 100) {
           return mark;
       } else {
           cout << "Marks must be between 0 and 100." << endl;
       }
   }
}

int main() {
   string name, another;
   float marks[3], total, average;
   string status;

   cout << "===== Student Result Management System =====" << endl;

   while (true) {
       cout << "\nEnter student name: ";
       cin >> name;

       for (int i = 0; i < 3; i++) {
           marks[i] = get_marks(i + 1);
       }

       calculate_results(marks, total, average, status);
       display_result(name, marks, total, average, status);

       cout << "\nAdd another student? (yes/no): ";
       cin >> another;
       if (another != "yes") {
           cout << "\nGoodbye!" << endl;
           break;
       }
   }

   return 0;
}