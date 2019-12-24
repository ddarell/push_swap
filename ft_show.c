/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddarell <ddarell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 23:31:22 by ddarell           #+#    #+#             */
/*   Updated: 2019/12/24 21:58:47 by ddarell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

void	ft_print_stack(t_ls *top)
{
	t_ls	*tmp;

	if (!(top))
	{
		return ;
	}
	if ((ft_bit_check(top->fl, INS)) == 1)
		ft_printf("{PUR}%d{EOC}\t", top->numb);
	else if ((ft_bit_check(top->fl, ORD)) == 1)
		ft_printf("{GRE}%d{EOC}\t", top->numb);
	else
		ft_printf("%d\t", top->numb);
	tmp = top->next;
	while (tmp != top)
	{
		if ((ft_bit_check(tmp->fl, INS)) == 1)
			ft_printf("{PUR}%d{EOC}\t", tmp->numb);
		else if ((ft_bit_check(tmp->fl, ORD)) == 1)
			ft_printf("{GRE}%d{EOC}\t", tmp->numb);
		else
			ft_printf("%d\t", tmp->numb);
		tmp = tmp->next;
	}
}

void	ft_print_stacks(t_ls *head_a, t_ls *head_b)
{
	ft_printf("(A - top) ||\t");
	ft_print_stack(head_a);
	ft_printf("\n");
	ft_printf("(B - top) ||\t");
	ft_print_stack(head_b);
	ft_printf("\n\n");
}

void	ft_show(t_sr *sr, t_ls *head_a, t_ls *head_b, char *op)
{
	int i;

	i = 3000000;
	system("clear");
	if (sr)
	{
		ft_printf("%s\nLast command:\t%s\nCommands used:\t%d\n",
		sr->info, op, sr->ops);
		ft_printf("_________________________\n");
		ft_print_stacks(head_a, head_b);
	}
	else
	{
		ft_printf("OPERATIONS DEMONSTRATION\nLast command:\t%s\n\n", op);
		ft_printf("_________________________\n");
		ft_print_stacks(head_a, head_b);
	}
	(op) ? usleep(i / 2) : usleep(i);
}
