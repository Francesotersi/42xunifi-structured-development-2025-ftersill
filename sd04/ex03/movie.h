#ifndef MOVIE_H
#define MOVIE_H

#define MAX_MOVIES 1000
#define MAX_LINE_LENGTH 256
#define MAX_TITLE_LENGTH 100
#define MAX_GENRE_LENGTH 50
#define DATE_LENGTH 11 // YYYY-MM-DD + null

typedef struct {
    int id;
    char title[MAX_TITLE_LENGTH];
    char genre[MAX_GENRE_LENGTH];
    int watched;        // 0 or 1
    int rating;         // 1-10 if watched, 0 otherwise
    char date_watched[DATE_LENGTH]; // empty if unwatched
} Movie;

typedef struct {
    Movie movies[MAX_MOVIES];
    int count;
    int max_id;
} Watchlist;

typedef struct {
    int total_movies;
    int watched_count;
    int unwatched_count;
    double avg_rating;
    // Can add genre breakdowns here
} WatchlistStats;

#endif