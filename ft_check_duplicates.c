#include "checker.h"

void	ft_check_duplicates(t_ls *node, t_ls *head)
{
	int	num;

	num = node->numb;
	if (node == head)
		return ;
	while (node != head)
	{
		node = node->prev;
		if (node->numb == num)
			ft_error();
	}
}
