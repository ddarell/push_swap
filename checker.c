/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddarell <ddarell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 23:35:01 by ddarell           #+#    #+#             */
/*   Updated: 2019/12/21 23:19:30 by ddarell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

static int	get_fd(int *fd, int *ac, char *filename)
{
	*fd = open(filename, O_RDONLY);
	if (*fd == -1)
		ft_no_file();
	*ac -= 1;
	return (1);
}

int			main(int ac, char **av)
{
	t_ls	*head_a;
	t_ls	*head_b;
	int 	fl;
	int 	fd;

	head_a = NULL;
	head_b = NULL;
	av += ft_check_options(av, &ac, &fl);
//	av = (ft_bit_check(fl, FRD)) ? av + get_fd(&fd, &ac, *av) : av;
	if (ac < 2)
		return (0);
	ft_fill_stack_a(&head_a, av, ac);
	ft_read_exec_commands(fd, &head_a, &head_b, fl);
	if (head_b == NULL && ft_check_sort(head_a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_free_ls(&head_a);
	ft_free_ls(&head_b);
	return (0);
}
