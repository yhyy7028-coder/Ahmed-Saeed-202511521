#include "notepad.h"

int main() {
    int choice;
    string filename;

    do {
        cout << endl;
        cout << "===== SIMPLE NOTEPAD =====" << endl;
        cout << "1. Write File" << endl;
        cout << "2. Read File" << endl;
        cout << "3. Append File" << endl;
        cout << "4. Exit" << endl;
        cout << "====" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        if (choice != 4) {
            cout << "Enter filename: ";
            getline(cin, filename);
        }

        switch (choice) {
            case 1: writeFile(filename); break;
            case 2: readFile(filename); break;
            case 3: appendFile(filename); break;
            case 4: cout << "Goodbye!" << endl; break;
            default: cout << "Invalid choice." << endl;
        }

    } while (choice != 4);

    return 0;
}