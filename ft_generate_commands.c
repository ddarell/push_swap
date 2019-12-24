/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate_commands.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddarell <ddarell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 23:34:34 by ddarell           #+#    #+#             */
/*   Updated: 2019/12/24 18:40:57 by ddarell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

static t_ls	*run_while_ord(t_ls *run, int *counter)
{
	while (ft_bit_check(run->fl, ORD))
	{
		*counter += 1;
		run = run->prev;
	}
	return (run);
}

static void	set_direction(t_sr *sr, t_ls *tmp)
{
	t_ls	*run;
	t_ls	*best;
	int		i;
	int		k;
	int		max;

	k = 0;
	best = tmp;
	max = 0;
	while (k < sr->a_els / 2 && sr->nsrt_els_a)
	{
		i = 0;
		run = tmp->prev;
		if (!(ft_bit_check(tmp->fl, ORD)) && ft_bit_check(run->fl, ORD))
			run = run_while_ord(run, &i);
		if (i && i > (k - 1) * 2)
		{
			max = (max < i) ? i : max;
			best = (max == i) ? tmp : best;
		}
		k = k + i + 1;
		tmp = run;
	}
	ft_bit_on(&best->fl, LDIR);
}

static void	check_sorted_data(t_sr *sr, t_ls *head_a)
{
	t_ls	*head_a_dup;

	head_a_dup = NULL;
	ft_strcpy(sr->info, "from NUMBERS to ORDERS");
	if (!(sr->sorted = (int *)malloc(sizeof(int) * (sr->a_els + 1))))
		ft_error();
	ft_fill_array(sr, head_a);
	ft_sort_array(sr);
	ft_init_elem_ord(sr, head_a);
	(ft_bit_check(sr->fl, VIS)) ? ft_show(sr, head_a, NULL, "") : 1;
	head_a_dup = ft_dup_ls(head_a_dup, head_a);
	ft_strcpy(sr->info, "SORTED DATA detected");
	ft_detect_sorted_data(sr, head_a, &head_a_dup);
	sr->nsrt_els_a = sr->a_els - sr->srt_els_a;
	(ft_bit_check(sr->fl, VIS)) ? ft_show(sr, head_a, NULL, "") : 1;
	ft_free_ls(&head_a_dup);
	free(sr->sorted);
	sr->sorted = NULL;
}

void		ft_generate_commands(t_sr *sr, t_ls **head_a, t_ls **head_b)
{
	check_sorted_data(sr, *head_a);
	ft_strcpy(sr->info, "going to START POINT");
	set_direction(sr, *head_a);
	while (!(ft_bit_check((*head_a)->fl, LDIR)))
		ft_run_rra(sr, head_a, head_b);
	ft_strcpy(sr->info, "pushing UNSORTED to B");
	while (sr->nsrt_els_a)
	{
		if ((ft_check_sa(sr, head_a, head_b)) == 1)
			continue;
		if ((ft_check_pa(sr, head_a, head_b)) == 1)
			continue;
		if ((ft_check_pb(sr, head_a, head_b)) == 1)
			continue;
		else
			ft_check_rr(sr, head_a, head_b);
	}
	ft_strcpy(sr->info, "inserting SORTED");
	while (sr->b_els)
		ft_insert(sr, head_a, head_b);
	ft_strcpy(sr->info, "going to END POINT");
	ft_finish_sort(sr, head_a, head_b);
	ft_strcpy(sr->info, "FINISHED");
}
