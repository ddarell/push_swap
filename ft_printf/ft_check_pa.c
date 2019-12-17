#include "ps_header.h"

static void	run_pa(t_srt_data *srt_data, t_ls **head_a, t_ls **head_b)
{
	t_cm		*cm;

	ft_add_command(&srt_data->cm, "pa");
	ft_pa(head_a, head_b);
	srt_data->a_els += 1;
	srt_data->b_els -= 1;
	srt_data->srt_els_a += 1;
	if (srt_data->sma_a > (*head_a)->numb)
		srt_data->sma_a = (*head_a)->numb;
	else if (srt_data->big_a < (*head_a)->numb)
		srt_data->big_a = (*head_a)->numb;
//	if (srt_data->sma_b == (*head_a)->numb)
//		srt_data->sma_b = ft_search_min(*head_b);
//	if (srt_data->big_b == (*head_a)->numb)
//		srt_data->big_b = ft_search_max(*head_b);
}

static void	find_segment_borders(t_ls **prev, t_ls **next, t_ls *top)
{
	t_ls *tmp;

	tmp = top->prev;
	while (!(ft_bit_check(top->fl, ORD)))
		top = top->next;
	*next = top;
	while (!(ft_bit_check(tmp->fl, ORD)))
		tmp = tmp->next;
	*prev = tmp;
}

int	ft_check_pa(t_srt_data *srt_data, t_ls **head_a, t_ls **head_b)
{
	t_ls *prev;
	t_ls *next;

	if (!(*head_b))
		return (0);
	if (srt_data->a_els == 1)
		return (1);
	find_segment_borders(&prev, &next, *head_a);
	if (((*head_b)->numb < next->numb && (*head_b)->numb > prev->numb) ||
		((*head_b)->numb > next->numb && (*head_b)->numb < prev->numb && prev->numb > next->numb))
	{
		run_pa(srt_data, head_a, head_b);
		return (1);
	}
	return (0);
}
