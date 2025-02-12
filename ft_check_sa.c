/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_sa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddarell <ddarell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 18:32:14 by ddarell           #+#    #+#             */
/*   Updated: 2019/12/24 21:54:31 by ddarell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

static void	run_sa(t_sr *sr, t_ls **head_a, t_ls **head_b)
{
	(ft_bit_check(sr->fl, VIS)) ? ft_show(sr, *head_a, *head_b, "sa") : 1;
	ft_add_command(&sr->cm, "sa");
	ft_sa(head_a, head_b);
	sr->ops += 1;
	sr->srt_els_a += 1;
	sr->nsrt_els_a -= 1;
	ft_bit_on(&(*head_a)->fl, ORD);
	ft_bit_on(&(*head_a)->next->fl, ORD);
	(ft_bit_check(sr->fl, VIS)) ? ft_show(sr, *head_a, *head_b, "sa_done") : 1;
}

t_ls		*find_srt_pair(t_ls *pair, int *delta)
{
	t_ls *min_bdr;
	t_ls *max_bdr;

	min_bdr = pair->next;
	while (!(ft_bit_check(min_bdr->fl, ORD)))
	{
		min_bdr = min_bdr->next;
		*delta += 1;
	}
	if (pair->numb < min_bdr->numb)
		return (NULL);
	max_bdr = min_bdr->next;
	while (!(ft_bit_check(max_bdr->fl, ORD)))
		max_bdr = max_bdr->next;
	if (pair->numb < max_bdr->numb || min_bdr->numb > max_bdr->numb)
		return (min_bdr);
	return (NULL);
}

t_ls		*find_nsrt_pair(t_ls *max_bdr, int *delta)
{
	t_ls *min_bdr;
	t_ls *pair;

	min_bdr = max_bdr->prev;
	pair = max_bdr->next;
	while (!(ft_bit_check(min_bdr->fl, ORD)))
		min_bdr = min_bdr->prev;
	while (!(ft_bit_check(pair->fl, ORD)))
	{
		if ((pair->numb < max_bdr->numb && pair->numb > min_bdr->numb) ||
			(pair->numb > min_bdr->numb && min_bdr->numb > max_bdr->numb))
			return (pair);
		pair = pair->next;
		*delta += 1;
	}
	return (NULL);
}

int			ft_check_sa(t_sr *sr, t_ls **head_a, t_ls **head_b)
{
	t_ls	*pair;
	int		delta;

	delta = 0;
	if (sr->a_els < 3)
		return (0);
	if (ft_bit_check((*head_a)->fl, ORD))
		pair = find_nsrt_pair(*head_a, &delta);
	else
		pair = find_srt_pair(*head_a, &delta);
	if (!(pair))
		return (0);
	if (delta)
		return (0);
	ft_bit_on(&(*head_a)->next->fl, INS);
	ft_bit_on(&(*head_a)->fl, INS);
	(ft_bit_check(sr->fl, VIS)) ? ft_show(sr, *head_a, *head_b, "") : 1;
	run_sa(sr, head_a, head_b);
	ft_bit_off(&(*head_a)->next->fl, INS);
	ft_bit_off(&(*head_a)->fl, INS);
	return (1);
}
