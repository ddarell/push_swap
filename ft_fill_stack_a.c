#include "checker.h"

static void		cycle_list(t_ls *node, t_ls *head)
{
	if (node)
	{
		node->next = head;
		head->prev = node;
	}
}

static long int	next_num(char *str)
{
	char *tmp;

	tmp = str;
	while (*str == ' ' || *str == '\r' || *str == '\v'
			|| *str == '\f' || *str == '\t' || *str == '\n')
		str++;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
		str++;
	if (!(*str == ' ' || *str == '\r' || *str == '\v'
		 || *str == '\f' || *str == '\t' || *str == '\n' || *str == 0))
		ft_error();
	return (str - tmp);
}

static void		check_null(char *str)
{
	while (*str == ' ' || *str == '\r' || *str == '\v'
		   || *str == '\f' || *str == '\t' || *str == '\n')
		str++;
	if (*str == '-' || *str == '+')
		str++;
	if (*str != '0')
		ft_error();
	while (*str == '0')
		str++;
	if (!(*str == ' ' || *str == '\r' || *str == '\v'
		  || *str == '\f' || *str == '\t' || *str == '\n' || *str == 0))
		ft_error();
}

//check $ARG behavior "1 2 3 4" == one str or four
//improve "   0  " behavior - error or not

static int		get_num(char *str)
{
	int i;

	i = ft_atoi_spec(str);
	if (i == 0)
		check_null(str);
	return (i);
}

void ft_fill_a(t_ls **head, char **av, int ac)
{
	t_ls	*node;
	int		i;

	i = 0;
	node = NULL;
	while (++i < ac)
	{
		if (*av[i] == 0)
			ft_error();
		while (*av[i])
		{
			if (node == NULL)
			{
				node = ft_add_node(node, get_num(av[i]));
				*head = node;
			}
			else
			{
				node = ft_add_node(node, get_num(av[i]));
				ft_check_duplicates(node, *head);
			}
			av[i] += next_num(av[i]);
		}
	}
	cycle_list(node, *head);
}
//first arg at the top of the stack
//sorting - top (smallest) -> down (biggest)
//1
//2
//3
//4
//5
//6