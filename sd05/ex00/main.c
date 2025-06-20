#include "header.h"

int	main(int argc, char **argv)
{
	t_catalog	catalog;
	char		*input;
	int			choice;

	if (argc != 2)
	{
		ft_printf("Usage: %s <catalog_file>\n", argv[0]);
		return (1);
	}
	display_welcome();
	load_catalog(&catalog, argv[1]);
	while (1)
	{
		display_menu();
		display_prompt();
		input = get_next_line(STDIN_FILENO);
		choice = ft_atoi(input);
		free(input);
		if (choice == 1)
			search_menu(&catalog);
		else if (choice == 2)
			list_books(&catalog);
		else if (choice == 3)
			add_book_menu(&catalog);
		else if (choice == 4)
			remove_book_menu(&catalog);
		else if (choice == 5)
			break ;
		else
			ft_printf("Invalid choice\n");
	}
	display_exit();
	return (0);
}