#ifndef OPERATIONS_H
#define OPERATIONS_H

#include "movie.h"

void add_movie(Watchlist *watchlist);
void mark_watched(Watchlist *watchlist);
void update_movie(Watchlist *watchlist);
void delete_movie(Watchlist *watchlist);
void list_movies(Watchlist *watchlist);
void search_movies(Watchlist *watchlist);
void filter_movies(Watchlist *watchlist);
WatchlistStats generate_stats(Watchlist *watchlist);

#endif