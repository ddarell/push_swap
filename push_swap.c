/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddarell <ddarell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 23:18:46 by ddarell           #+#    #+#             */
/*   Updated: 2019/12/24 21:45:10 by ddarell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

static int	get_fd(int *fd, int *ac, char *filename)
{
	*fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (*fd == -1)
		ft_error();
	*ac -= 1;
	return (1);
}

static void	print_commands(t_cm *cm, int fd)
{
	if (fd)
	{
		while (cm)
		{
			ft_fprintf(fd, "%s\n", cm->cmd);
			cm = cm->next;
		}
		if ((close(fd)) == -1)
			ft_error();
	}
	else
	{
		while (cm)
		{
			ft_printf("%s\n", cm->cmd);
			cm = cm->next;
		}
	}
}

static void	free_cm(t_cm **cm)
{
	t_cm *front;
	t_cm *back;

	if (!(*cm))
		return ;
	back = *cm;
	front = (*cm)->next;
	free(back);
	while (front)
	{
		back = front;
		front = front->next;
		free(back);
	}
	*cm = NULL;
}

int			main(int ac, char **av)
{
	t_ls	*head_a;
	t_ls	*head_b;
	t_sr	sr;
	int		fd;

	fd = 0;
	head_a = NULL;
	head_b = NULL;
	av += ft_check_options(av, &ac, &sr.fl);
	(ft_bit_check(sr.fl, HLP)) ? ft_usage_ps() : 1;
	if (ac < 2 + (ft_bit_check(sr.fl, FRD)))
		return (0);
	av = (ft_bit_check(sr.fl, FRD)) ? av + get_fd(&fd, &ac, *(av + 1)) : av;
	ft_fill_stack_a(&head_a, av, ac);
	ft_set_sr(&sr, head_a);
	(ft_bit_check(sr.fl, VIS)) ? ft_show(&sr, head_a, head_b, "") : 1;
	ft_generate_commands(&sr, &head_a, &head_b);
	(ft_bit_check(sr.fl, VIS)) ? ft_show(&sr, head_a, head_b, "") : 1;
	(ft_bit_check(sr.fl, VIS)) ? system("clear") : 1;
	print_commands(sr.cm, fd);
	free_cm(&sr.cm);
	ft_free_ls(&head_a);
	ft_free_ls(&head_b);
	return (0);
}
