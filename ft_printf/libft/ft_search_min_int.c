#include "libft.h"

int ft_seach_min_int(int *tab, int size)
{
	int min;

	min = *tab;
	while (--size)
	{
		tab++;
		if (*tab < min)
			min = *tab;
	}
	return (min);
}
