/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_pa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddarell <ddarell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 18:39:32 by ddarell           #+#    #+#             */
/*   Updated: 2019/12/24 21:54:14 by ddarell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

static void	run_pa(t_sr *sr, t_ls **head_a, t_ls **head_b)
{
	(ft_bit_check(sr->fl, VIS)) ? ft_show(sr, *head_a, *head_b, "pa") : 1;
	ft_add_command(&sr->cm, "pa");
	ft_pa(head_a, head_b);
	sr->ops += 1;
	sr->a_els += 1;
	sr->b_els -= 1;
	sr->srt_els_a += 1;
	ft_bit_on(&(*head_a)->fl, ORD);
	(ft_bit_check(sr->fl, VIS)) ? ft_show(sr, *head_a, *head_b, "pa_done") : 1;
}

int			ft_pa_ability(t_ls *head_a, t_ls *head_b)
{
	t_ls *prev;
	t_ls *next;

	if (!(head_b))
		return (0);
	prev = head_a->prev;
	next = head_a;
	while (!(ft_bit_check(next->fl, ORD)))
		next = next->next;
	while (!(ft_bit_check(prev->fl, ORD)))
		prev = prev->prev;
	if ((head_b->numb < next->numb && head_b->numb > prev->numb) ||
		(head_b->numb > prev->numb && prev->numb > next->numb))
		return (1);
	return (0);
}

int			ft_check_pa(t_sr *sr, t_ls **head_a, t_ls **head_b)
{
	if (!(*head_b))
		return (0);
	if (sr->a_els == 1)
	{
		run_pa(sr, head_a, head_b);
		return (1);
	}
	if ((ft_pa_ability(*head_a, *head_b)) == 1)
	{
		run_pa(sr, head_a, head_b);
		return (1);
	}
	return (0);
}
