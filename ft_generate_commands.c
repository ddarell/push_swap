#include "ps_header.h"

static void set_direction(t_srt_data *srt_data, t_ls *head_a)
{
	t_ls	*tmp;
	t_ls	*point;
	int		min;
	int		curr;
	int 	i;

	i = 0;
	tmp = head_a;
//	curr = ft_count_path(srt_data, head_a, tmp);
	curr = 0;//
	min = curr;
	tmp = head_a->prev;
	point = tmp;
	while (i < srt_data->nsrt_els_a)
	{
		tmp = tmp->prev;
		if (!(ft_bit_check(tmp->fl, ORD)))
		{
			i++;
//			if (ft_bit_check(tmp->prev->fl, ORD))
//				curr = ft_count_path(srt_data, head_a, tmp);
			if (curr < min)
			{
				curr = min;
				point = tmp;
			}
		}
	}
	ft_bit_on(&point->fl, LDIR);
}

static void check_sorted_data(t_srt_data *srt_data, t_ls *head_a)
{
	t_ls	*head_a_dup;

	head_a_dup = NULL;
	if (!(srt_data->sorted = (int *)malloc(sizeof(int) * srt_data->a_els + 1)))
		ft_error();
	ft_fill_array(srt_data, head_a);
	ft_sort_array(srt_data);
	ft_init_elem_ord(srt_data, head_a);
	head_a_dup = ft_dup_ls(head_a_dup, head_a);
	ft_detect_sorted_data(srt_data, head_a, &head_a_dup);
	srt_data->nsrt_els_a = srt_data->a_els - srt_data->srt_els_a;
	ft_free_ls(&head_a_dup);
//	free(srt_data->sorted);
//	srt_data->sorted = NULL;
}

void	ft_generate_commands(t_srt_data *srt_data, t_ls **head_a, t_ls **head_b)
{
	check_sorted_data(srt_data, *head_a);
	set_direction(srt_data, *head_a);
//	match_what_swap(srt_data, *head_a);
	while (!(ft_bit_check((*head_a)->fl, LDIR)))
	{
		if ((ft_check_pa(srt_data, head_a, head_b)) == 1)
			continue;
		else if ((check_pb(srt_data, head_a, head_b)) == 1)
			continue;
		else
			check_rrr(srt_data, head_a, head_b);
//		if (ft_bit_check(&(*head_a)->fl, SWAP))
//			check_swap_nodes(srt_data, head_a, head_b);
	}
	while (srt_data->nsrt_els_a)
	{
		if ((ft_check_pa(srt_data, head_a, head_b)) == 1)
			continue;
		else if ((check_pb(srt_data, head_a, head_b)) == 1)
			continue;
		else
			check_rr(srt_data, head_a, head_b);
//		if (ft_bit_check(&(*head_a)->fl, SWAP))
//			check_swap_nodes(srt_data, head_a, head_b);
	}
//	insert_data(srt_data, head_a, head_b);
	while (srt_data->b_els)
	{
		determine_point(srt_data, head_a, head_b);
		go_to_point(srt_data, head_a, head_b);
		ft_check_pa(srt_data, head_a, head_b);
	}
}
