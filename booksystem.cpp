// Name   : Ahmed Yahia Fadl Saeed
// Roll   : 202511521

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void pauseScreen() {
    cout << "\nPress Enter to go back...";
    cin.ignore();
    cin.get();
}

void displayDivider() {
    cout << "\033[34m========================================\033[0m" << endl;
}

void showChapter1_Origin() {
    displayDivider();
    cout << "\033[33m Chapter 1: The Origin of C++ \033[0m" << endl;
    displayDivider();
    cout << "\nC++ was created by Bjarne Stroustrup at Bell Labs in 1979." << endl;
    cout << "It began as 'C with Classes'." << endl;
    cout << "The name 'C++' was coined in 1983." << endl;
    pauseScreen();
}

void showChapter2_Evolution() {
    displayDivider();
    cout << "\033[33m Chapter 2: Evolution of C++ \033[0m" << endl;
    displayDivider();
    cout << "\n  1979 - C with Classes" << endl;
    cout << "  1983 - Renamed to C++" << endl;
    cout << "  1998 - First ISO standard: C++98" << endl;
    cout << "  2011 - Major update: C++11" << endl;
    cout << "  2017 - C++17" << endl;
    cout << "  2020 - C++20" << endl;
    pauseScreen();
}

void showChapter3_Influence() {
    displayDivider();
    cout << "\033[33m Chapter 3: Influence & Language Family \033[0m" << endl;
    displayDivider();
    cout << "\nFortran --> Algol 60 --> BCPL --> C --> C++" << endl;
    cout << "Simula 67 (OOP) + C --> C++" << endl;
    cout << "\nLanguages influenced by C++: Java, C#, Rust" << endl;
    pauseScreen();
}

void historyMenu() {
    int choice;
    do {
        displayDivider();
        cout << "\033[36m  HISTORY OF C++ \033[0m" << endl;
        displayDivider();
        cout << "  [1] Chapter 1 : The Origin of C++" << endl;
        cout << "  [2] Chapter 2 : Evolution of C++" << endl;
        cout << "  [3] Chapter 3 : Influence & Language Family" << endl;
        cout << "  [0] Back" << endl;
        displayDivider();
        cout << "Select chapter: ";
        cin >> choice;

        switch (choice) {
            case 1: showChapter1_Origin();    break;
            case 2: showChapter2_Evolution(); break;
            case 3: showChapter3_Influence(); break;
            case 0: break;
            default: cout << "\033[31mInvalid option.\033[0m" << endl;
        }
    } while (choice != 0);
}

void learnDataTypes() {
    displayDivider();
    cout << "\033[33m Chapter 1: Data Types \033[0m" << endl;
    displayDivider();
    cout << "\n  int    - Integer   (e.g. int age = 20;)" << endl;
    cout << "  float  - Decimal   (e.g. float pi = 3.14f;)" << endl;
    cout << "  char   - Character (e.g. char grade = 'A';)" << endl;
    cout << "  bool   - True/False(e.g. bool isOn = true;)" << endl;
    cout << "  string - Text      (e.g. string name = \"Ahmed\";)" << endl;
    pauseScreen();
}

void learnControlFlow() {
    displayDivider();
    cout << "\033[33m Chapter 2: Control Flow \033[0m" << endl;
    displayDivider();
    cout << "\nif / else if / else:" << endl;
    cout << "  if (score >= 90) cout << \"A\";" << endl;
    cout << "  else cout << \"B\";" << endl;
    cout << "\nswitch / case:" << endl;
    cout << "  switch(x) { case 1: ... break; }" << endl;
    pauseScreen();
}

void learnLoops() {
    displayDivider();
    cout << "\033[33m Chapter 3: Loops \033[0m" << endl;
    displayDivider();
    cout << "\nfor loop:" << endl;
    cout << "  for (int i = 0; i < 5; i++)" << endl;
    cout << "\nwhile loop:" << endl;
    cout << "  while (x < 10) { x++; }" << endl;
    cout << "\ndo-while loop:" << endl;
    cout << "  do { cin >> pin; } while (pin != 1234);" << endl;
    pauseScreen();
}

void learnArrays() {
    displayDivider();
    cout << "\033[33m Chapter 4: Arrays \033[0m" << endl;
    displayDivider();
    cout << "\n1D Array:" << endl;
    cout << "  int scores[5] = {90, 85, 78, 92, 88};" << endl;
    cout << "\n2D Array:" << endl;
    cout << "  int matrix[2][3] = {{1,2,3},{4,5,6}};" << endl;
    pauseScreen();
}

void learnFileStreams() {
    displayDivider();
    cout << "\033[33m Chapter 5: File Streams \033[0m" << endl;
    displayDivider();

    ifstream file("filestreams.txt");
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    } else {
        cout << "\nHeader needed: #include <fstream>" << endl;
        cout << "\n-- Writing --" << endl;
        cout << "  ofstream outFile(\"data.txt\");" << endl;
        cout << "  outFile << \"Hello\" << endl;" << endl;
        cout << "  outFile.close();" << endl;
        cout << "\n-- Reading --" << endl;
        cout << "  ifstream inFile(\"data.txt\");" << endl;
        cout << "  string line;" << endl;
        cout << "  while (getline(inFile, line))" << endl;
        cout << "      cout << line << endl;" << endl;
        cout << "  inFile.close();" << endl;
    }
    pauseScreen();
}

void learnMenu() {
    int choice;
    do {
        displayDivider();
        cout << "\033[36m  LEARN ABOUT C++ \033[0m" << endl;
        displayDivider();
        cout << "  [1] Chapter 1 : Data Types" << endl;
        cout << "  [2] Chapter 2 : Control Flow" << endl;
        cout << "  [3] Chapter 3 : Loops" << endl;
        cout << "  [4] Chapter 4 : Arrays" << endl;
        cout << "  [5] Chapter 5 : File Streams" << endl;
        cout << "  [0] Back" << endl;
        displayDivider();
        cout << "Select chapter: ";
        cin >> choice;

        switch (choice) {
            case 1: learnDataTypes();   break;
            case 2: learnControlFlow(); break;
            case 3: learnLoops();       break;
            case 4: learnArrays();      break;
            case 5: learnFileStreams();  break;
            case 0: break;
            default: cout << "\033[31mInvalid option.\033[0m" << endl;
        }
    } while (choice != 0);
}

int main() {
    int choice;
    do {
        displayDivider();
        cout << "\033[35m  Foundations and History of C++  \033[0m" << endl;
        displayDivider();
        cout << "  [1] History of C++" << endl;
        cout << "  [2] Learn About C++" << endl;
        cout << "  [0] Exit" << endl;
        displayDivider();
        cout << "Your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: historyMenu(); break;
            case 2: learnMenu();   break;
            case 0:
                cout << "\033[33mGoodbye! Keep coding!\033[0m" << endl;
                break;
            default:
                cout << "\033[31mInvalid option.\033[0m" << endl;
        }
    } while (choice != 0);

    return 0;
}