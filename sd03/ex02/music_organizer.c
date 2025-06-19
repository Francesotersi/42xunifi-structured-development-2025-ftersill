#include "music_organizer.h"

struct MusicLibrary *organize_music_library(const char *directory_path)
{
	struct MusicFile *song = NULL;
	struct MusicLibrary *library = create_music_library();
	if (library == NULL)
		return (free(library), NULL);
	const char **filenames = scan_directory(directory_path);
	if (filenames == NULL)
		return (free(filenames), NULL);
	for (int i = 0; filenames[i] != NULL; i++)
	{
		song = process_music_file(directory_path, filenames[i]);
		if (song == NULL)
			continue;
		update_music_library(library, song);
		free(song);
	}
	free(filenames);
	return (library);
}
