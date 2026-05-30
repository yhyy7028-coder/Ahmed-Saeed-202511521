#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "LibraryBook.h"

const int MAX_BOOKS = 100;

extern LibraryBook books[MAX_BOOKS];
extern int bookCount;

void addBook();
void displayBooks();
void searchBook();
void borrowBookMenu();
void returnBookMenu();
void displayOverdueBooks();
void calculateTotalFines();

#endif