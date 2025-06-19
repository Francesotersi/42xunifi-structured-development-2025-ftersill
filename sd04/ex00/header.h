#ifndef BOOK_LIBRARY_H
# define BOOK_LIBRARY_H

#define MAX_BOOKS 1000
#define MAX_LINE_LENGTH 256

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
