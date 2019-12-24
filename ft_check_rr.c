/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_rr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddarell <ddarell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 18:37:50 by ddarell           #+#    #+#             */
/*   Updated: 2019/12/24 18:38:46 by ddarell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

void		ft_run_rb(t_sr *sr, t_ls **head_a, t_ls **head_b)
{
	ft_add_command(&sr->cm, "rb");
	ft_rb(head_a, head_b);
	sr->ops += 1;
	(ft_bit_check(sr->fl, VIS)) ? ft_show(sr, *head_a, *head_b, "rb") : 1;
}

void		ft_run_ra(t_sr *sr, t_ls **head_a, t_ls **head_b)
{
	ft_add_command(&sr->cm, "ra");
	ft_ra(head_a, head_b);
	sr->ops += 1;
	(ft_bit_check(sr->fl, VIS)) ? ft_show(sr, *head_a, *head_b, "ra") : 1;
}

void		ft_run_rr(t_sr *sr, t_ls **head_a, t_ls **head_b)
{
	ft_add_command(&sr->cm, "rr");
	ft_rr(head_a, head_b);
	sr->ops += 1;
	(ft_bit_check(sr->fl, VIS)) ? ft_show(sr, *head_a, *head_b, "rr") : 1;
}

static int	rr_ability(t_ls *head_a, t_ls *head_b)
{
	t_ls	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(head_b) || head_b->next == head_b)
		return (0);
	tmp = head_a->next;
	while (!((ft_pa_ability(tmp, head_b))))
	{
		tmp = tmp->next;
		i++;
	}
	tmp = head_a->next;
	while (!((ft_pa_ability(tmp, head_b->next))))
	{
		tmp = tmp->next;
		j++;
	}
	return (j < i);
}

int			ft_check_rr(t_sr *sr, t_ls **head_a, t_ls **head_b)
{
	if (!(*head_a) || sr->a_els < 2)
		return (0);
	if ((rr_ability(*head_a, *head_b)) == 1)
	{
		ft_run_rr(sr, head_a, head_b);
		return (1);
	}
	ft_run_ra(sr, head_a, head_b);
	return (0);
}
