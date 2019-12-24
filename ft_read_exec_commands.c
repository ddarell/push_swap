/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_command.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddarell <ddarell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 23:32:33 by ddarell           #+#    #+#             */
/*   Updated: 2019/12/11 23:36:06 by ddarell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

static int	compare_symbol(char compared, char s0, char s1, char s2)
{
	if (s0 && compared == s0)
		return (0);
	if (s1 && compared == s1)
		return (1);
	if (s2 && compared == s2)
		return (2);
	ft_error();
	return (-1);
}

static int	check_command(char *cmd)
{
	int i;

	i = ft_strlen(cmd);
	if (i == 2)
	{
		if (cmd[0] == 's')
			return (compare_symbol(cmd[1], 'a', 'b', 's'));
		else if (cmd[0] == 'p')
			return (3 + compare_symbol(cmd[1], 'a', 'b', 0));
		else if (cmd[0] == 'r')
			return (5 + compare_symbol(cmd[1], 'a', 'b', 'r'));
	}
	else if (i == 3)
	{
		if (cmd[0] == 'r' && cmd[1] == 'r')
			return (8 + compare_symbol(cmd[2], 'a', 'b', 'r'));
	}
	ft_error();
	return (-1);
}

static int	get_next_command(int fd, char *cmd)
{
	int i;
	int ret;

	i = 0;
	ret = 0;
	while (i < 4 && (ret = read(fd, cmd + i, 1)) > 0)
	{
		if (*(cmd + i) == '\n')
			break ;
		i++;
	}
	if (ret == -1 || (ret > 0 && (i > 3 || i < 2)) || (ret == 0 && i != 0))
		ft_error();
	cmd[i] = 0;
	return (ret);
}

void ft_read_exec_commands(int fd, t_ls **head_a, t_ls **head_b, int fl)
{
	char	cmd[5];
	void	(*command[11])(t_ls **, t_ls **);

	ft_set_commands(command);
	while ((get_next_command(fd, cmd)) > 0)
	{
		command[check_command(cmd)](head_a, head_b);
		(ft_bit_check(fl, VIS)) ? ft_show(NULL, *head_a, *head_b, cmd) : 1;
	}
}
