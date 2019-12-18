#include "ps_header.h"

static void	match_sorted_numbers(t_ls *top, int *tab)
{
	t_ls *tmp;

	while (*tab)
	{
		tmp = ft_search_ls(top, *tab);
		if (tmp)
			ft_bit_on(&tmp->fl, ORD);
		tab++;
	}
}

static int find_data_sorted(t_ls *top, int *data)
{
	int i;
	t_ls *tmp;

	i = 0;
	data[i] = top->numb;
	tmp = top->next;
	while (tmp != top)
	{
		if (data[i] < tmp->numb)
		{
			i++;
			data[i] = tmp->numb;
		}
		tmp = tmp->next;
	}
	i++;
	data[i] = 0;
	return (i);
}

static int remove_next_extr(t_ls **top)
{
	t_ls *tmp;

	if (!(*top))
		return (0);
	tmp = (*top)->next;
	while (tmp != *top)
	{
		if (tmp->numb != (*top)->numb && tmp->numb != (*top)->prev->numb
			&& tmp->numb > tmp->prev->numb && tmp->numb > tmp->next->numb)
		{
			tmp = ft_remove_node(top, tmp);
			free(tmp);
			tmp = NULL;
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

void ft_detect_sorted_data(t_srt_data *srt_data, t_ls *top, t_ls **dup)
{
	int *tmp;
	int curr;

	if (!(tmp = (int *)malloc(sizeof(int) * srt_data->a_els + 1)))
		ft_error();
	*dup = ft_search_ls(*dup, 1);
	*tmp = 0;
	curr = find_data_sorted(*dup, srt_data->sorted);
	int i = -1;//
/*	while (srt_data->sorted[++i])//
		ft_printf("__%d__", srt_data->sorted[i]);//
	ft_printf("\n_______________________________\n");//*/
	while (remove_next_extr(dup))
	{
		if ((find_data_sorted(*dup, tmp)) >= curr)
		{
			curr = ft_int_tab_copy(srt_data->sorted, tmp);
		}
/*		i = -1;//
		while (tmp[++i])//
			ft_printf("__%d__", tmp[i]);//
		ft_printf("\n_______________________________\n");//*/
	}
/*	i = -1;
	while (srt_data->sorted[++i])//
		ft_printf("__%d__", srt_data->sorted[i]);//
	ft_printf("\n_______________________________\n");//*/
	match_sorted_numbers(top, srt_data->sorted);
	srt_data->srt_els_a = curr;
	free(tmp);
}
