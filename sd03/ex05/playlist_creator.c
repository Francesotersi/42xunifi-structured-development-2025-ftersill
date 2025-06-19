#include "playlist_creator.h"

struct Playlist *create_playlist(void)
{
	int mood_variations = 0;
	int popular_song_required = 0;
	struct MoodSettings *mood = NULL;
	struct FilterSettings *filters = NULL;
	struct SongData *song = NULL;

	mood = analyze_user_mood();
	if (mood == NULL)
		return NULL;
	filters = default_filters();
	if (filters == NULL)
		return (free_mood_settings(mood), NULL);
	mood_variations = get_mood_variations(mood);
	filters = refine_filters(filters);
	if (filters == NULL)
		return (free_mood_settings(mood), NULL);
	popular_song_required = filters_require_popular_song(filters);
	if (popular_song_required)
	{
		song = fetch_popular_song();
		if (song == NULL)
			return (free_filter_settings(filters), free_mood_settings(mood), NULL);
	}
	else
	{
		song = fetch_niche_song();
		if (song == NULL)
			return (free_filter_settings(filters), free_mood_settings(mood), NULL);
	}

	return (combine_with_mood_playlist(song, mood));
}