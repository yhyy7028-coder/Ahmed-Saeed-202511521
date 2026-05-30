#ifndef LIBRARYBOOK_H
#define LIBRARYBOOK_H

#include <string>
using namespace std;

class LibraryBook {
private:
    int bookID;
    string title;
    string author;
    string borrowerName;
    int daysBorrowed;
    bool isBorrowed;

public:
    LibraryBook();
    LibraryBook(int id, string title, string author);
    ~LibraryBook();

    int getBookID() const;
    string getTitle() const;
    string getAuthor() const;
    string getBorrowerName() const;
    int getDaysBorrowed() const;
    bool getIsBorrowed() const;

    void setBookID(int id);
    void setTitle(string t);
    void setAuthor(string a);
    void setBorrowerName(string name);
    void setDaysBorrowed(int days);
    void setIsBorrowed(bool status);

    void displayBook() const;
    bool isOverdue() const;
    double calculateFine() const;

    static const int MAX_BORROW_DAYS = 14;
    static const double FINE_PER_DAY;
};

#endif