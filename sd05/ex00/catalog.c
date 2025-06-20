#include "header.h"

void	remove_invalid(t_catalog *catalog)
{
	int	i;
	int	j;

	i = 0;
	while (i < catalog->count)
	{
		if (catalog->books[i].id <= 0 || !catalog->books[i].title
			|| !catalog->books[i].author || !*catalog->books[i].title
			|| !*catalog->books[i].author)
		{
			free(catalog->books[i].title);
			free(catalog->books[i].author);
			j = i;
			while (j < catalog->count - 1)
			{
				catalog->books[j] = catalog->books[j + 1];
				j++;
			}
			catalog->count--;
		}
		else
			i++;
	}
}

void	add_book(t_catalog *catalog, t_book book)
{
	int	i;

	if (catalog->count >= MAX_BOOKS)
	{
		ft_printf("Error: Library is full!\n");
		return ;
	}
	i = -1;
	while (++i < catalog->count)
	{
		if (catalog->books[i].id == book.id)
		{
			ft_printf("Error: Book with ID %d already exists!\n", book.id);
			return ;
		}
	}
	catalog->books[catalog->count] = book;
	catalog->count++;
	ft_printf("Book added successfully!\n");
}

void	remove_book(t_catalog *catalog, int id)
{
	int	i;
	int	j;

	i = -1;
	while (++i < catalog->count)
	{
		if (catalog->books[i].id == id)
		{
			free(catalog->books[i].title);
			free(catalog->books[i].author);
			j = i;
			while (j < catalog->count - 1)
			{
				catalog->books[j] = catalog->books[j + 1];
				j++;
			}
			catalog->count--;
			ft_printf("Book with ID %d removed successfully!\n", id);
			return ;
		}
	}
	ft_printf("Error: Book with ID %d not found!\n", id);
}

t_book	*find_book(t_catalog *catalog, int id, char *title, char *author)
{
	int	i;
	int	match;

	i = -1;
	while (++i < catalog->count)
	{
		match = 1;
		if (id != 0 && catalog->books[i].id != id)
			match = 0;
		if (title && !ft_strstr(catalog->books[i].title, title))
			match = 0;
		if (author && !ft_strstr(catalog->books[i].author, author))
			match = 0;
		if (match)
			return (&catalog->books[i]);
	}
	return (0);
}