#ifndef FILE_OPERATIONS_H
#define FILE_OPERATIONS_H

#include "movie.h"

int load_watchlist(const char *filename, Watchlist *watchlist);
int save_watchlist(const char *filename, Watchlist *watchlist);
void free_watchlist(Watchlist *watchlist);

#endif