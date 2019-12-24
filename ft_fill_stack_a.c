/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_stack_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddarell <ddarell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 23:32:42 by ddarell           #+#    #+#             */
/*   Updated: 2019/12/11 23:37:22 by ddarell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

static long int	next_num(char *str)
{
	char *tmp;

	tmp = str;
	while (*str == ' ' || *str == '\t' || *str == '\n')
		str++;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
		str++;
	if (!(*str == ' ' || *str == '\t' || *str == '\n' || *str == 0))
		ft_error();
	return (str - tmp);
}

static void		check_null(char *str)
{
	while (*str == ' ' || *str == '\t' || *str == '\n')
		str++;
	if (*str == '-' || *str == '+')
		str++;
	if (*str != '0')
		ft_error();
	while (*str == '0')
		str++;
	if (!(*str == ' ' || *str == '\t' || *str == '\n' || *str == 0))
		ft_error();
}

static int		get_num(char *str)
{
	int i;

	i = ft_atoi_spec(str);
	if (i == 0)
		check_null(str);
	return (i);
}

void			ft_fill_stack_a(t_ls **head, char **av, int ac)
{
	t_ls		*node;
	int			i;
	long int	j;
	char		*str;

	i = 0;
	j = 0;
	node = NULL;
	while (++i < ac && av[i])
	{
		if (!(str = ft_strtrim(av[i])))
			ft_error();
		if (*str == 0)
			ft_error();
		while (str[j])
		{
			node = ft_new_node(get_num(str + j));
			ft_add_node_back(head, node);
			ft_check_duplicates(node, *head);
			j += next_num(str + j);
		}
		free(str);
		j = 0;
	}
}
