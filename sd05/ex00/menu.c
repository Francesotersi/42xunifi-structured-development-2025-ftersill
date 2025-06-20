#include "header.h"

void	search_menu(t_catalog *catalog)
{
	int		choice;
	char	*input;
	char	*search;
	t_book	*results[MAX_BOOKS];
	int		count;
	int		i;

	ft_printf("\nSearch by:\n1. ID\n2. Title\n3. Author\n4. Back\n> ");
	input = get_next_line(STDIN_FILENO);
	choice = ft_atoi(input);
	free(input);
	if (choice == 4)
		return ;
	ft_printf("Search term: ");
	search = get_next_line(STDIN_FILENO);
	trim_whitespace(search);
	count = 0;
	i = -1;
	while (++i < catalog->count)
	{
		if ((choice == 1 && catalog->books[i].id == ft_atoi(search))
			|| (choice == 2 && ft_strstr(catalog->books[i].title, search))
			|| (choice == 3 && ft_strstr(catalog->books[i].author, search)))
			results[count++] = &catalog->books[i];
	}
	free(search);
	display_books((t_book *)results, count);
}

void	add_book_menu(t_catalog *catalog)
{
	t_book	new;
	char	*input;

	ft_printf("\nEnter book ID: ");
	input = get_next_line(STDIN_FILENO);
	new.id = ft_atoi(input);
	free(input);
	ft_printf("Enter title: ");
	new.title = get_next_line(STDIN_FILENO);
	ft_printf("Enter author: ");
	new.author = get_next_line(STDIN_FILENO);
	add_book(catalog, new);
}

void	remove_book_menu(t_catalog *catalog)
{
	char	*input;
	int		id;

	ft_printf("\nEnter book ID to remove: ");
	input = get_next_line(STDIN_FILENO);
	id = ft_atoi(input);
	free(input);
	remove_book(catalog, id);
}