#ifndef BOOK_LIBRARY_H
# define BOOK_LIBRARY_H

#define MAX_BOOKS 1000
#define MAX_LINE_LENGTH 256

#include "display.h"
#include "library.h"

typedef struct {
    int id;
    char *title;
    char *author;
} Book;

typedef struct {
    Book books[MAX_BOOKS];
    int count;
} Catalog;

#endif
