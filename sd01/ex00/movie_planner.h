#ifndef MOVIE_PLANNER_H
# define MOVIE_PLANNER_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef Preferences;

typedef Plan;

typedef MovieList;

typedef struct Plan
{
	char *title;
	char *description;
	char **movies;
	int movie_count;
} Plan;

// Returns user preferences. Returns NULL on failure.
struct Preferences *get_user_preferences(void);
// Returns a list of movies matching the given preferences. Returns NULL on failure.
struct MovieList *find_movies(struct Preferences *prefs);
// Returns a movie night plan from the given list. Returns NULL on failure.
struct Plan *build_plan(struct MovieList *list);

struct Plan *create_movie_night_plan(void);

#endif