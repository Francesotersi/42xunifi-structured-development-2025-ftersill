#ifndef LIBRARY_H
#define LIBRARY_H

#include "header.h"

// removes invalid books from the library
void remove_invalid_books(void);
// adds a book to the library
void add_book(Book book);
// removes a book from the library by its ID
void remove_book(int id);
// finds a book in the library by its ID, title, author, or year 
// (put NULL or 0 when not searching by that field)
// returns a pointer to the book if found, NULL otherwise
Book *find_book(int id, char *title, char *author, int year);
// displays the list of the searched books
void display_books(Book *books, int count);
// display the list of all books in the library
void list_books(void);

#endif
