#include "libft.h"

int	ft_search_int_tab(int *tab, int size, int num)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (tab[i] == num)
			return (i);
		i++;
	}
	return (-1);
}
