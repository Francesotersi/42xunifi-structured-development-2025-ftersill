#ifndef VALIDATION_H
#define VALIDATION_H

#include "movie.h"

int is_valid_id(int id, Watchlist *watchlist);
int is_valid_title(const char *title);
int is_valid_genre(const char *genre);
int is_valid_watched_flag(int flag);
int is_valid_rating(int rating, int watched);
int is_valid_date(const char *date, int required);
void trim_whitespace(char *str);

#endif