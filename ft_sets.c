/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddarell <ddarell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 23:30:28 by ddarell           #+#    #+#             */
/*   Updated: 2019/12/22 23:22:36 by ddarell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

void	ft_set_commands(void (**command)(t_ls **, t_ls **))
{
	command[0] = &ft_sa;
	command[1] = &ft_sb;
	command[2] = &ft_ss;
	command[3] = &ft_pa;
	command[4] = &ft_pb;
	command[5] = &ft_ra;
	command[6] = &ft_rb;
	command[7] = &ft_rr;
	command[8] = &ft_rra;
	command[9] = &ft_rrb;
	command[10] = &ft_rrr;
}

void	ft_set_ins(t_ins *ins)
{
	ins->ins_a = NULL;
	ins->ins_b = NULL;
	ins->ra = 0;
	ins->rra = 0;
	ins->rb = 0;
	ins->rrb = 0;
	ins->rr = 0;
	ins->rrr = 0;
	ins->ops = 0;
	ins->ofs = 0;
}

void	ft_set_srt_data(t_sr *sr, t_ls *head_a)
{
	sr->a_els = ft_count_ls(head_a);
	sr->b_els = 0;
	sr->srt_els_a = 0;
	sr->nsrt_els_a = 0;
	sr->cm = NULL;
	sr->sorted = NULL;
	ft_set_ins(&sr->ins);
	sr->ops = 0;
}
