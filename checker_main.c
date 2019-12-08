#include "checker.h"

int	main(int ac, char **av)
{
	t_ls *head;

	head = NULL;
	if (ac != 2)
		ft_error();
	ft_set_ls(&head, av[1]);
}
