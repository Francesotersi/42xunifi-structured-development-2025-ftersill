#ifndef DISPLAY_H
#define DISPLAY_H

#include "movie.h"
void display_menu(void);
void display_movie(Movie *movie);
void display_stats(WatchlistStats *stats);
void display_error(const char *message);
int get_menu_choice(void);
void get_string_input(const char *prompt, char *buffer, int max_length);
int get_int_input(const char *prompt, int min, int max);
void get_date_input(const char *prompt, char *buffer);

#endif