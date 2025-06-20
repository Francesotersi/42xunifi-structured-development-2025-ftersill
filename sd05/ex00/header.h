#ifndef BOOK_LIBRARY_H
# define BOOK_LIBRARY_H

#define MAX_BOOKS 1000
#define MAX_LINE_LENGTH 256

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>

typedef struct s_book{
	int id;
	char *title;
	char *author;
} t_book;

typedef struct	s_catalog {
	t_book	books[MAX_BOOKS];
	int		count;
}				t_catalog;

#endif
