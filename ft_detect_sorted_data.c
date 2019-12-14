#include "ps_header.h"

static void	match_sorted_numbers(t_ls *top, int *tab)
{
	t_ls *tmp;

	tmp = top->prev;
	while (*tab)
	{
		while (top->ord != *tab && tmp->ord != *tab)
		{
			top = top->next;
			tmp = tmp->prev;
		}
		if (top->ord == *tab)
			top->asc = 1;
		else
			tmp->asc = 1;
		tab++;
	}
}

static int find_data_sorted(t_ls *top, int *data)
{
	int i;
	t_ls *tmp;

	i = 0;
	data[i] = top->ord;
	tmp = top->next;
	while (tmp != top)
	{
		if (data[i] < tmp->ord)
		{
			i++;
			data[i] = tmp->ord;
		}
		tmp = tmp->next;
	}
	i++;
	data[i] = 0;
	return (i);
}

static int remove_next_extr(t_ls *top)
{
	t_ls *tmp;

	if (!(top))
		return (0);
	tmp = top->next;
	while (tmp != top)
	{
		if (tmp->ord != top->ord && tmp->ord != top->prev->ord
			&& tmp->ord > tmp->prev->ord && tmp->ord > tmp->next->ord)
		{
			tmp = ft_remove_node(&top, tmp);
			free(tmp);
			tmp = NULL;
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

void ft_detect_sorted_data(t_srt_data *srt_data, t_ls *top, t_ls *dup)
{
	int *tmp;
	int curr;

	if (!(tmp = (int *)malloc(sizeof(int) * srt_data->a_elmnts + 1)))
		ft_error();
	while (dup->ord != 1)
		dup = dup->next;
	*tmp = 0;
	curr = find_data_sorted(dup, srt_data->sorted);
/*	int i = -1;//
	while (srt_data->sorted[++i])//
		ft_printf("__%d__", srt_data->sorted[i]);//
	ft_printf("\n_______________________________\n");//*/
	while (remove_next_extr(dup))
	{
		if ((find_data_sorted(dup, tmp)) >= curr)
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
	free(tmp);
}
