/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_rrr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddarell <ddarell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 18:37:39 by ddarell           #+#    #+#             */
/*   Updated: 2019/12/24 21:54:57 by ddarell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

void		ft_run_rrb(t_sr *sr, t_ls **head_a, t_ls **head_b)
{
	(ft_bit_check(sr->fl, VIS)) ? ft_show(sr, *head_a, *head_b, "rrb") : 1;
	ft_add_command(&sr->cm, "rrb");
	ft_rrb(head_a, head_b);
	sr->ops += 1;
	(ft_bit_check(sr->fl, VIS)) ? ft_show(sr, *head_a, *head_b, "rrb_done") : 1;
}

void		ft_run_rra(t_sr *sr, t_ls **head_a, t_ls **head_b)
{
	(ft_bit_check(sr->fl, VIS)) ? ft_show(sr, *head_a, *head_b, "rra") : 1;
	ft_add_command(&sr->cm, "rra");
	ft_rra(head_a, head_b);
	sr->ops += 1;
	(ft_bit_check(sr->fl, VIS)) ? ft_show(sr, *head_a, *head_b, "rra_done") : 1;
}

void		ft_run_rrr(t_sr *sr, t_ls **head_a, t_ls **head_b)
{
	(ft_bit_check(sr->fl, VIS)) ? ft_show(sr, *head_a, *head_b, "rrr") : 1;
	ft_add_command(&sr->cm, "rrr");
	ft_rrr(head_a, head_b);
	sr->ops += 1;
	(ft_bit_check(sr->fl, VIS)) ? ft_show(sr, *head_a, *head_b, "rrr_done") : 1;
}

static int	rrr_ability(t_ls *head_a, t_ls *head_b)
{
	if (!(head_b) || head_b->next == head_b)
		return (0);
	if ((ft_pa_ability(head_a->prev, head_b)) <
	(ft_pa_ability(head_a->prev, head_b->prev)))
		return (1);
	return (0);
}

int			ft_check_rrr(t_sr *sr, t_ls **head_a, t_ls **head_b)
{
	if (!(*head_a) || sr->a_els < 2)
		return (0);
	if ((rrr_ability(*head_a, *head_b)) == 1)
	{
		ft_run_rrr(sr, head_a, head_b);
		return (1);
	}
	ft_run_rra(sr, head_a, head_b);
	return (0);
}
