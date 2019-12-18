/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddarell <ddarell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 23:31:22 by ddarell           #+#    #+#             */
/*   Updated: 2019/12/11 23:36:25 by ddarell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

void	ft_print_stack(t_ls *top)
{
	t_ls	*tmp;

	if (!(top))
	{
		ft_printf("\n");
		return ;
	}
	ft_printf("%d\t", top->numb);
	tmp = top->next;
	while (tmp != top)
	{
		ft_printf("%d\t", tmp->numb);
		tmp = tmp->next;
	}
	ft_printf("\n");
}

void	ft_print_stacks(t_ls *head_a, t_ls *head_b)
{
	ft_printf("_____________________________\n");
	ft_print_stack(head_a);
	ft_print_stack(head_b);
	ft_printf("_____________________________\n");
}
