#include "ps_header.h"

static void	run_pb(t_srt_data *srt_data, t_ls **head_a, t_ls **head_b)
{
	ft_add_command(&srt_data->cm, "pb");
	ft_pb(head_a, head_b);
	srt_data->a_els -= 1;
	srt_data->b_els += 1;
	srt_data->nsrt_els_a -= 1;
	if (srt_data->sma_b > (*head_b)->numb)
		srt_data->sma_b = (*head_b)->numb;
	else if (srt_data->big_b < (*head_b)->numb)
		srt_data->big_b = (*head_b)->numb;
//	if (srt_data->sma_a == (*head_b)->numb)
//		srt_data->sma_a = ft_search_min(*head_a);
//	if (srt_data->big_a == (*head_b)->numb)
//		srt_data->big_a = ft_search_max(*head_a);
	ft_print_stacks(*head_a, *head_b);//
}

static int	pb_ability(t_ls *head_a)
{
	if (!(ft_bit_check(head_a->fl, ORD)))
		return (1);
	return (0);
}

int	ft_check_pb(t_srt_data *srt_data, t_ls **head_a, t_ls **head_b)
{
	if (!(*head_a))
		return (0);
	if ((pb_ability(*head_a)) == 1)
	{
		run_pb(srt_data, head_a, head_b);
		return (1);
	}
	return (0);
}
