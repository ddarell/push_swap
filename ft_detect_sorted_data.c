/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_detect_sorted_data.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddarell <ddarell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 18:30:31 by ddarell           #+#    #+#             */
/*   Updated: 2019/12/24 18:41:19 by ddarell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

static void	set_each_point_limited(t_ls *dup)
{
	t_ls *cur;
	t_ls *run;

	dup->fl = 0;
	dup->prev->fl = 0;
	cur = dup->next;
	while (cur != dup->prev)
	{
		run = cur;
		while (run != dup)
		{
			if (run->numb < cur->numb)
				cur->fl += 1;
			run = run->next;
		}
		cur = cur->next;
	}
}

static void	match_sorted_numbers(t_ls *top, int *tab)
{
	t_ls *tmp;

	while (*tab)
	{
		tmp = ft_search_ls_num(top, *tab);
		if (tmp)
			ft_bit_on(&tmp->fl, ORD);
		tab++;
	}
}

static int	find_data_sorted(t_ls *top, int *data, int *max_lim)
{
	int		i;
	t_ls	*tmp;

	i = 0;
	data[i] = top->numb;
	tmp = top->next;
	*max_lim = 0;
	while (tmp != top)
	{
		if (data[i] < tmp->numb)
		{
			i++;
			data[i] = tmp->numb;
			*max_lim = (*max_lim < tmp->fl) ? tmp->fl : *max_lim;
		}
		tmp = tmp->next;
	}
	i++;
	data[i] = 0;
	return (i);
}

static int	remove_next_extr(t_ls **top, int max_lim)
{
	t_ls *tmp;

	if (!max_lim)
		return (0);
	while ((tmp = ft_search_ls_fl(*top, max_lim)))
	{
		tmp = ft_remove_node(top, tmp);
		free(tmp);
		tmp = NULL;
	}
	return (1);
}

void		ft_detect_sorted_data(t_sr *sr, t_ls *top, t_ls **dup)
{
	int *tmp;
	int curr;
	int max_lim;

	if (!(tmp = (int *)malloc(sizeof(int) * (sr->a_els + 1))))
		ft_error();
	*dup = ft_search_ls_num(*dup, 1);
	*tmp = 0;
	set_each_point_limited(*dup);
	curr = find_data_sorted(*dup, sr->sorted, &max_lim);
	while (remove_next_extr(dup, max_lim))
	{
		if ((find_data_sorted(*dup, tmp, &max_lim)) > curr)
			curr = ft_int_tab_copy(sr->sorted, tmp);
	}
	match_sorted_numbers(top, sr->sorted);
	sr->srt_els_a = curr;
	free(tmp);
}
