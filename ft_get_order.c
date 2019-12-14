#include "ps_header.h"

void	ft_init_elem_ord(t_srt_data *srt_data, t_ls *head_a)
{
	int		i;
	t_ls	*tmp;

	tmp = head_a->next;
	i = -1;
	while (++i < srt_data->a_elmnts)
		if (srt_data->sorted[i] == head_a->numb)
		{
			head_a->ord = i + 1;
			break ;
		}
	while (tmp != head_a)
	{
		i = -1;
		while (++i < srt_data->a_elmnts)
			if (srt_data->sorted[i] == tmp->numb)
			{
				tmp->ord = i + 1;
				break ;
			}
		tmp = tmp->next;
	}
}

void	ft_sort_array(t_srt_data *srt_data)
{
	int *tmp_min;
	int i;
	int j;

	i = 0;
	while (i < srt_data->a_elmnts)
	{
		j = i;
		tmp_min = srt_data->sorted + i;
		while (j < srt_data->a_elmnts)
		{
			if (srt_data->sorted[j] < *tmp_min)
				tmp_min = srt_data->sorted + j;
			j++;
		}
		ft_int_swap(srt_data->sorted + i, tmp_min);
		i++;
	}
}

void	ft_fill_array(t_srt_data *srt_data, t_ls *head_a)
{
	int i;

	i = 0;
	while (i < srt_data->a_elmnts)
	{
		srt_data->sorted[i] = head_a->numb;
		i++;
		head_a = head_a->next;
	}
}
