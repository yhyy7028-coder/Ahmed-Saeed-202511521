#include "Functions.h"
#include <iostream>
#include <iomanip>
using namespace std;

#define RESET    "\033[0m"
#define BOLD     "\033[1m"
#define RED      "\033[31m"
#define GREEN    "\033[32m"
#define YELLOW   "\033[33m"
#define BLUE     "\033[34m"
#define CYAN     "\033[36m"
#define WHITE    "\033[37m"

LibraryBook books[MAX_BOOKS];
int bookCount = 0;

void addBook() {
    if (bookCount >= MAX_BOOKS) {
        cout << RED << "Library is full!" << RESET << "\n";
        return;
    }
    int id;
    string title, author;
    cout << BOLD << CYAN << "\n--- Add New Book ---" << RESET << "\n";
    cout << YELLOW << "Enter Book ID   : " << RESET;
    cin >> id;
    cin.ignore();
    for (int i = 0; i < bookCount; i++) {
        if (books[i].getBookID() == id) {
            cout << RED << "Book ID already exists!" << RESET << "\n";
            return;
        }
    }
    cout << YELLOW << "Enter Title     : " << RESET;
    getline(cin, title);
    cout << YELLOW << "Enter Author    : " << RESET;
    getline(cin, author);
    books[bookCount] = LibraryBook(id, title, author);
    bookCount++;
    cout << GREEN << "✔ Book added successfully!" << RESET << "\n";
}

void displayBooks() {
    if (bookCount == 0) {
        cout << YELLOW << "\nNo books in the library yet.\n" << RESET;
        return;
    }
    cout << BOLD << CYAN << "\n=== All Books (" << bookCount << " total) ===" << RESET << "\n";
    for (int i = 0; i < bookCount; i++) books[i].displayBook();
}

void searchBook() {
    int id;
    cout << BOLD << CYAN << "\n--- Search Book by ID ---" << RESET << "\n";
    cout << YELLOW << "Enter Book ID: " << RESET;
    cin >> id;
    for (int i = 0; i < bookCount; i++) {
        if (books[i].getBookID() == id) {
            cout << GREEN << "\n✔ Book found:\n" << RESET;
            books[i].displayBook();
            return;
        }
    }
    cout << RED << "✘ Book not found.\n" << RESET;
}

void borrowBookMenu() {
    int id, days;
    string borrower;
    cout << BOLD << CYAN << "\n--- Borrow Book ---" << RESET << "\n";
    cout << YELLOW << "Enter Book ID      : " << RESET;
    cin >> id;
    cin.ignore();
    for (int i = 0; i < bookCount; i++) {
        if (books[i].getBookID() == id) {
            if (books[i].getIsBorrowed()) {
                cout << RED << "✘ Already borrowed by "
                     << books[i].getBorrowerName() << RESET << "\n";
                return;
            }
            cout << YELLOW << "Enter Borrower Name: " << RESET;
            getline(cin, borrower);
            cout << YELLOW << "Enter Days Borrowed: " << RESET;
            cin >> days;
            books[i].setBorrowerName(borrower);
            books[i].setDaysBorrowed(days);
            books[i].setIsBorrowed(true);
            cout << GREEN << "✔ Book borrowed successfully!\n" << RESET;
            return;
        }
    }
    cout << RED << "✘ Book not found.\n" << RESET;
}

void returnBookMenu() {
    int id;
    cout << BOLD << CYAN << "\n--- Return Book ---" << RESET << "\n";
    cout << YELLOW << "Enter Book ID: " << RESET;
    cin >> id;
    for (int i = 0; i < bookCount; i++) {
        if (books[i].getBookID() == id) {
            if (!books[i].getIsBorrowed()) {
                cout << RED << "✘ This book was not borrowed.\n" << RESET;
                return;
            }
            if (books[i].isOverdue()) {
                cout << RED << "⚠ Fine to pay: "
                     << fixed << setprecision(2)
                     << books[i].calculateFine() << " Rwf\n" << RESET;
            } else {
                cout << GREEN << "✔ Book returned. No fine.\n" << RESET;
            }
            books[i].setBorrowerName("");
            books[i].setDaysBorrowed(0);
            books[i].setIsBorrowed(false);
            return;
        }
    }
    cout << RED << "✘ Book not found.\n" << RESET;
}

void displayOverdueBooks() {
    cout << BOLD << RED << "\n=== Overdue Books ===" << RESET << "\n";
    bool found = false;
    for (int i = 0; i < bookCount; i++) {
        if (books[i].isOverdue()) {
            books[i].displayBook();
            found = true;
        }
    }
    if (!found) cout << GREEN << "✔ No overdue books.\n" << RESET;
}

void calculateTotalFines() {
    double total = 0.0;
    cout << BOLD << YELLOW << "\n=== Fine Summary ===" << RESET << "\n";
    bool found = false;
    for (int i = 0; i < bookCount; i++) {
        if (books[i].isOverdue()) {
            double fine = books[i].calculateFine();
            cout << WHITE << "  \"" << books[i].getTitle() << "\" ("
                 << books[i].getBorrowerName() << ") -> "
                 << RED << fixed << setprecision(2) << fine << " Rwf\n" << RESET;
            total += fine;
            found = true;
        }
    }
    if (!found)
        cout << GREEN << "✔ No fines to report.\n" << RESET;
    else
        cout << BOLD << RED << "  Total Fines: "
             << fixed << setprecision(2) << total << " Rwf\n" << RESET;
}