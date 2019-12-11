/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddarell <ddarell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 23:35:01 by ddarell           #+#    #+#             */
/*   Updated: 2019/12/11 23:35:42 by ddarell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

static void	read_exec_commands(t_ls **head_a, t_ls **head_b)
{
	char	cmd[5];
	void	(*command[11])(t_ls **, t_ls **);

	ft_set_commands(command);
	while ((ft_get_next_command(0, cmd)) > 0)
	{
		command[check_command(cmd)](head_a, head_b);
		ft_printf("\n\n=========\n");//
		ft_print_stack(*head_a);//
		ft_printf("\n");//
		ft_print_stack(*head_b);//
		ft_printf("=========\n");//
	}
}

int			main(int ac, char **av)
{
	t_ls *head_a;
	t_ls *head_b;

	head_a = NULL;
	head_b = NULL;
	if (ac < 2)
		return (0);
	ft_fill_stack_a(&head_a, av, ac);
	ft_print_stack(head_a);//
	if (!(head_a))
		return (0);
	read_exec_commands(&head_a, &head_b);
	ft_printf("\n");//
	if (head_b == NULL && ft_check_sort(head_a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_free_ls(&head_a);
	ft_free_ls(&head_b);
	return (0);
}
