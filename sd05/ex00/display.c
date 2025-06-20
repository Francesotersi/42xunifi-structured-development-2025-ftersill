#include "header.h"

void	display_welcome(void)
{
	ft_printf("\n***************************************\n");
	ft_printf("* Welcome to the Community Library!   *\n");
	ft_printf("***************************************\n\n");
}

void	display_menu(void)
{
	ft_printf("\nMain Menu:\n");
	ft_printf("1. Search books\n");
	ft_printf("2. List all books\n");
	ft_printf("3. Add a book\n");
	ft_printf("4. Remove a book\n");
	ft_printf("5. Exit\n");
}

void	display_prompt(void)
{
	ft_printf("\nEnter your choice (1-5): ");
}

void	display_exit(void)
{
	ft_printf("\nThank you for using the Community Library!\n");
	ft_printf("Goodbye!\n\n");
}

void	display_books(t_book *books, int count)
{
	int	i;

	if (count == 0)
	{
		ft_printf("No books found.\n");
		return ;
	}
	ft_printf("\nFound %d book(s):\n", count);
	i = -1;
	while (++i < count)
	{
		ft_printf("ID: %d\n", books[i].id);
		ft_printf("Title: %s\n", books[i].title);
		ft_printf("Author: %s\n\n", books[i].author);
	}
}

void	list_books(t_catalog *catalog)
{
	int	i;

	if (catalog->count == 0)
	{
		ft_printf("The library is empty.\n");
		return ;
	}
	ft_printf("\nListing all %d books:\n", catalog->count);
	i = -1;
	while (++i < catalog->count)
	{
		ft_printf("Book %d:\n", i + 1);
		ft_printf("ID: %d\n", catalog->books[i].id);
		ft_printf("Title: %s\n", catalog->books[i].title);
		ft_printf("Author: %s\n\n", catalog->books[i].author);
	}
}