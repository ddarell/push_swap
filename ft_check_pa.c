#include "ps_header.h"

static void	run_pa(t_srt_data *srt_data, t_ls **head_a, t_ls **head_b)
{
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
	ft_bit_on(&(*head_a)->fl, ORD);
}

int ft_pa_ability(t_ls *head_a, t_ls *head_b)
{
	t_ls *prev;
	t_ls *next;

	prev = head_a->prev;
	next = head_a;
	while (!(ft_bit_check(next->fl, ORD)))
		next = next->next;
	while (!(ft_bit_check(prev->fl, ORD)))
		prev = prev->prev;
	if ((head_b->numb < next->numb && head_b->numb > prev->numb) ||
		(head_b->numb > prev->numb && prev->numb > next->numb))
		return (1);
	return (0);
}

int	ft_check_pa(t_srt_data *srt_data, t_ls **head_a, t_ls **head_b)
{
	if (!(*head_b))
		return (0);
	if (srt_data->a_els == 1)
	{
		run_pa(srt_data, head_a, head_b);
		return (1);
	}
	if ((ft_pa_ability(*head_a, *head_b)) == 1)
	{
		run_pa(srt_data, head_a, head_b);
		return (1);
	}
	return (0);
}
