#include "header.h"

void	load_catalog(t_catalog *catalog, const char *filename)
{
	int		fd;
	char	*line;
	char	*tokens[3];

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("Error");
		return ;
	}
	catalog->count = 0;
	while ((line = get_next_line(fd)) && catalog->count < MAX_BOOKS)
	{
		trim_whitespace(line);
		if (!*line)
		{
			free(line);
			continue ;
		}
		tokens[0] = ft_strtok(line, ",");
		tokens[1] = ft_strtok(NULL, ",");
		tokens[2] = ft_strtok(NULL, ",");
		if (tokens[0] && tokens[1] && tokens[2])
		{
			catalog->books[catalog->count].id = ft_atoi(tokens[0]);
			catalog->books[catalog->count].title = ft_strdup(tokens[1]);
			catalog->books[catalog->count].author = ft_strdup(tokens[2]);
			if (catalog->books[catalog->count].id > 0
				&& catalog->books[catalog->count].title
				&& catalog->books[catalog->count].author)
				catalog->count++;
		}
		free(line);
	}
	close(fd);
	remove_invalid(catalog);
}

void	trim_whitespace(char *str)
{
	char	*end;

	while (ft_isspace(*str))
		str++;
	if (!*str)
		return ;
	end = str + ft_strlen(str) - 1;
	while (end > str && ft_isspace(*end))
		end--;
	*(end + 1) = '\0';
}

void	str_to_lower(char *str)
{
	while (*str)
	{
		*str = ft_tolower(*str);
		str++;
	}
}