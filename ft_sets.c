/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddarell <ddarell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 23:30:28 by ddarell           #+#    #+#             */
/*   Updated: 2019/12/11 23:30:29 by ddarell          ###   ########.fr       */
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

void	ft_set_srt_data(t_srt_data *srt_data, t_ls *head_a)
{
	srt_data->a_els = ft_count_ls(head_a);
	srt_data->b_els = 0;
	srt_data->srt_els_a = 0;
	srt_data->nsrt_els_a = 0;
	srt_data->cm = NULL;
	srt_data->sorted = NULL;
	srt_data->sma_a = 1;
	srt_data->sma_b = srt_data->a_els;
	srt_data->big_a = 0;
	srt_data->big_b = 0;
	srt_data->ins_of = 0;
}
