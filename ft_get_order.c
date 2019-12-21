#include "ps_header.h"

void	ft_init_elem_ord(t_sr *sr, t_ls *head_a)
{
	int		i;
	t_ls	*tmp;

	tmp = head_a->next;
	i = -1;
	while (++i < sr->a_els)
		if (sr->sorted[i] == head_a->numb)
		{
			head_a->numb = i + 1;
			break ;
		}
	while (tmp != head_a)
	{
		i = -1;
		while (++i < sr->a_els)
			if (sr->sorted[i] == tmp->numb)
			{
				tmp->numb = i + 1;
				break ;
			}
		tmp = tmp->next;
	}
}

void	ft_sort_array(t_sr *sr)
{
	int *tmp_min;
	int i;
	int j;

	i = 0;
	while (i < sr->a_els)
	{
		j = i;
		tmp_min = sr->sorted + i;
		while (j < sr->a_els)
		{
			if (sr->sorted[j] < *tmp_min)
				tmp_min = sr->sorted + j;
			j++;
		}
		ft_int_swap(sr->sorted + i, tmp_min);
		i++;
	}
}

void	ft_fill_array(t_sr *sr, t_ls *head_a)
{
	int i;

	i = 0;
	while (i < sr->a_els)
	{
		sr->sorted[i] = head_a->numb;
		i++;
		head_a = head_a->next;
	}
}
