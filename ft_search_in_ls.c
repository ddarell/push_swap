#include "ps_header.h"

t_ls	*ft_search_ls(t_ls *top, int num)
{
	t_ls *tmp;

	tmp = top->prev;
	while (top->numb != num && tmp->numb != num && top != tmp && top->next != tmp)
	{
		top = top->next;
		tmp = tmp->prev;
	}
	if (top->numb == num)
		return (top);
	else if (tmp->numb == num)
		return (tmp);
	return (NULL);
}
