#include "ps_header.h"

int	ft_int_tab_copy(int *dst, int *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (i);
}
/*
int	ft_find_int_tab(int *tab, int num)
{
	while (*tab && *tab != num)
		tab++;
	return (*tab != 0);
}

void	ft_add_int_tab(int *tab, t_ls *node, t_ls *top)
{
	t_ls *tmp;

	while (*tab)
		tab++;
	*tab = node->ord;
	*(tab + 1) = 0;
	tab++;
	tmp = node->prev;
	while ()
}*/
