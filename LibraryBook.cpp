#include "LibraryBook.h"
#include <iostream>
#include <iomanip>
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

const double LibraryBook::FINE_PER_DAY = 50.0;

LibraryBook::LibraryBook() {
    bookID = 0;
    title = "Unknown";
    author = "Unknown";
    borrowerName = "";
    daysBorrowed = 0;
    isBorrowed = false;
}

LibraryBook::LibraryBook(int id, string t, string a) {
    bookID = id;
    title = t;
    author = a;
    borrowerName = "";
    daysBorrowed = 0;
    isBorrowed = false;
}

LibraryBook::~LibraryBook() {
    cout << MAGENTA << "[Destructor called for: \""
         << title << "\" (ID: " << bookID << ")]" << RESET << "\n";
}

int LibraryBook::getBookID() const { return bookID; }
string LibraryBook::getTitle() const { return title; }
string LibraryBook::getAuthor() const { return author; }
string LibraryBook::getBorrowerName() const { return borrowerName; }
int LibraryBook::getDaysBorrowed() const { return daysBorrowed; }
bool LibraryBook::getIsBorrowed() const { return isBorrowed; }

void LibraryBook::setBookID(int id) { bookID = id; }
void LibraryBook::setTitle(string t) { title = t; }
void LibraryBook::setAuthor(string a) { author = a; }
void LibraryBook::setBorrowerName(string name) { borrowerName = name; }
void LibraryBook::setDaysBorrowed(int days) { daysBorrowed = days; }
void LibraryBook::setIsBorrowed(bool status) { isBorrowed = status; }

void LibraryBook::displayBook() const {
    cout << CYAN << "--------------------------------------------" << RESET << "\n";
    cout << BOLD << BLUE  << "  Book ID     : " << RESET << WHITE << bookID  << RESET << "\n";
    cout << BOLD << BLUE  << "  Title       : " << RESET << WHITE << title   << RESET << "\n";
    cout << BOLD << BLUE  << "  Author      : " << RESET << WHITE << author  << RESET << "\n";
    if (isBorrowed) {
        cout << BOLD << YELLOW << "  Status      : " << RESET << YELLOW << "Borrowed" << RESET << "\n";
        cout << BOLD << BLUE   << "  Borrower    : " << RESET << WHITE << borrowerName << RESET << "\n";
        cout << BOLD << BLUE   << "  Days Borrowed: " << RESET << WHITE << daysBorrowed << RESET << "\n";
        if (isOverdue()) {
            int overdueDays = daysBorrowed - MAX_BORROW_DAYS;
            cout << BOLD << RED << "  ** OVERDUE by " << overdueDays << " day(s) **" << RESET << "\n";
            cout << BOLD << RED << "  Fine        : " << RESET << RED
                 << fixed << setprecision(2) << calculateFine() << " Rwf" << RESET << "\n";
        }
    } else {
        cout << BOLD << GREEN << "  Status      : " << RESET << GREEN << "Available" << RESET << "\n";
    }
    cout << CYAN << "--------------------------------------------" << RESET << "\n";
}

bool LibraryBook::isOverdue() const {
    return isBorrowed && (daysBorrowed > MAX_BORROW_DAYS);
}

double LibraryBook::calculateFine() const {
    if (!isOverdue()) return 0.0;
    return (daysBorrowed - MAX_BORROW_DAYS) * FINE_PER_DAY;
}