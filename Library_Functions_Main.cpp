#include <iostream>
#include "Functions.h"
using namespace std;

#define RESET    "\033[0m"
#define BOLD     "\033[1m"
#define RED      "\033[31m"
#define GREEN    "\033[32m"
#define YELLOW   "\033[33m"
#define BLUE     "\033[34m"
#define MAGENTA  "\033[35m"
#define CYAN     "\033[36m"
#define WHITE    "\033[37m"

int main() {
    int choice;
    do {
        cout << BOLD << CYAN << "\n=== LIBRARY BOOK BORROWING SYSTEM ===\n" << RESET;
        cout << BOLD << WHITE << "   Kigali Independent University\n" << RESET;
        cout << CYAN << "======================================\n" << RESET;
        cout << GREEN  << "1. Add New Book\n"          << RESET;
        cout << GREEN  << "2. Display All Books\n"     << RESET;
        cout << YELLOW << "3. Borrow Book\n"           << RESET;
        cout << YELLOW << "4. Return Book\n"           << RESET;
        cout << CYAN   << "5. Search Book by ID\n"     << RESET;
        cout << RED    << "6. Display Overdue Books\n"  << RESET;
        cout << RED    << "7. Calculate Total Fines\n"  << RESET;
        cout << MAGENTA << "8. Exit\n"                << RESET;
        cout << CYAN << "======================================\n" << RESET;
        cout << BOLD << WHITE << "Enter your choice: " << RESET;
        cin >> choice;

        switch (choice) {
            case 1: addBook();             break;
            case 2: displayBooks();        break;
            case 3: borrowBookMenu();      break;
            case 4: returnBookMenu();      break;
            case 5: searchBook();          break;
            case 6: displayOverdueBooks(); break;
            case 7: calculateTotalFines(); break;
            case 8: cout << BOLD << MAGENTA << "\nGoodbye! 👋\n" << RESET; break;
            default: cout << RED << "Invalid choice! Enter 1-8.\n" << RESET;
        }
    } while (choice != 8);
    return 0;
}