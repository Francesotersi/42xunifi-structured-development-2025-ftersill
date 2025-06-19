#include "movie_planner.h"

struct  Plan *create_movie_night_plan(void)
{
	struct Prefences *prefs = get_user_preferences();
	if (prefs == NULL)
		return (NULL);
	struct MovieList *list = find_movies(prefs);
	if (list == NULL)
		return (NULL);
	struct Plan *plan = build_plan(list);
	if (plan == NULL)
		return (NULL);
	return (plan);
}