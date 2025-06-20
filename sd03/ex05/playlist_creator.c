#include "playlist_creator.h"

static struct MoodSettings *init_mood_settings(void)
{
	struct MoodSettings *mood = analyze_user_mood();
	return mood;
}

static struct FilterSettings *init_filter_settings(struct MoodSettings *mood)
{
	struct FilterSettings *filters = default_filters();
	if (filters == NULL)
		return (NULL);
	filters = refine_filters(filters);
	if (filters == NULL)
		return (NULL);
	return (filters);
}

static struct SongData *select_song(struct FilterSettings *filters, struct MoodSettings *mood)
{
	struct SongData *song = NULL;
	if (filters_require_popular_song(filters))
		song = fetch_popular_song();
	else
		song = fetch_niche_song();
	return (song);
}

struct Playlist *create_playlist(void)
{
	struct MoodSettings *mood = NULL;
	struct FilterSettings *filters = NULL;
	struct SongData *song = NULL;

	mood = init_mood_settings();
	if (mood == NULL)
		return (NULL);
	filters = init_filter_settings(mood);
	if (filters == NULL)
		return (free_mood_settings(mood), NULL);
	song = select_song(filters, mood);
	if (song == NULL)
		return (free_filter_settings(filters), free_mood_settings(mood), NULL);
	return (combine_with_mood_playlist(song, mood));
}