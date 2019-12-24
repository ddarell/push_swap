/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finish_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddarell <ddarell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 18:29:12 by ddarell           #+#    #+#             */
/*   Updated: 2019/12/24 18:41:44 by ddarell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

void	ft_finish_sort(t_sr *sr, t_ls **head_a, t_ls **head_b)
{
	t_ls	*next;
	int		ra;
	int		rra;

	next = *head_a;
	ra = 0;
	while (next->numb != 1)
	{
		next = next->next;
		ra++;
	}
	rra = (ra != 0) ? sr->a_els - ra : 0;
	if (ra <= rra)
	{
		while (--ra >= 0)
			ft_run_ra(sr, head_a, head_b);
	}
	else
	{
		while (--rra >= 0)
			ft_run_rra(sr, head_a, head_b);
	}
}
