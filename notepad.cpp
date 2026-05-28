#include "notepad.h"

void writeFile(string filename) {
    ofstream file(filename);
    if (!file) {
        cout << "Error: Could not create file." << endl;
        return;
    }
    cout << "Type your text. Type 'END' to stop." << endl;
    string line;
    while (true) {
        getline(cin, line);
        if (line == "END") break;
        file << line << endl;
    }
    file.close();
    cout << "File saved!" << endl;
}

void readFile(string filename) {
    ifstream file(filename);
    if (!file) {
        cout << "Error: File not found." << endl;
        return;
    }
    cout << "===== File Contents =====" << endl;
    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }
    cout << "====" << endl;
    file.close();
}

void appendFile(string filename) {
    ofstream file(filename, ios::app);
    if (!file) {
        cout << "Error: Could not open file." << endl;
        return;
    }
    cout << "Type text to add. Type 'END' to stop." << endl;
    string line;
    while (true) {
        getline(cin, line);
        if (line == "END") break;
        file << line << endl;
    }
    file.close();
    cout << "Text appended!" << endl;
}