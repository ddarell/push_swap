#include "checker.h"

static long int	next_num(char *str)
{
	char *tmp;

	tmp = str;
	while (*str == ' ' || *str == '\r' || *str == '\v'
			|| *str == '\f' || *str == '\t' || *str == '\n')
		str++;
	while (*str >= '0' && *str <= '9')
		str++;
	return (str - tmp);
}

static int		get_num(char *str)
{
	int i = ft_atoi(str);
	return (i);
}

void	ft_set_ls(t_ls **head, char	*str)
{
	while (*str)
	{
//		ft_new_node(*head, get_num(str));
		str += next_num(str);
	}
}
