#include "ps_header.h"
/*
static void set_direction(t_sr *sr, t_ls *head_a)
{
	t_ls	*tmp;
	t_ls	*last_nsrt;
	int		nord_counter;
	int 	i;

	i = -1;
	nord_counter = 0;
	tmp = head_a;
	while(++i <= sr->a_els / 2)
	{
		tmp = tmp->next;
		if (!(ft_bit_check(tmp->fl, ORD)))
			nord_counter += 1;
	}
	if (!(nord_counter))
		ft_bit_on(&tmp->next->fl, LDIR);
	else
		ft_bit_on(&head_a->fl, LDIR);
}
*/
static void check_sorted_data(t_sr *sr, t_ls *head_a)
{
	t_ls	*head_a_dup;

	head_a_dup = NULL;
	if (!(sr->sorted = (int *)malloc(sizeof(int) * sr->a_els + 1)))
		ft_error();
	ft_fill_array(sr, head_a);
	ft_sort_array(sr);
	ft_init_elem_ord(sr, head_a);
	head_a_dup = ft_dup_ls(head_a_dup, head_a);
	ft_detect_sorted_data(sr, head_a, &head_a_dup);
	sr->nsrt_els_a = sr->a_els - sr->srt_els_a;
	ft_free_ls(&head_a_dup);
	free(sr->sorted);
	sr->sorted = NULL;
}

void	ft_generate_commands(t_sr *sr, t_ls **head_a, t_ls **head_b)
{
	check_sorted_data(sr, *head_a);
//	set_direction(sr, *head_a);
/*	while (!(ft_bit_check((*head_a)->fl, LDIR)))
	{
		if ((ft_check_pa(sr, head_a, head_b)) == 1)
			continue;
		else if ((ft_check_pb(sr, head_a, head_b)) == 1)
			continue;
		else
			ft_check_rrr(sr, head_a, head_b);
//		if (ft_bit_check(&(*head_a)->fl, SWAP))
//			check_swap_nodes(sr, head_a, head_b);
	}*/
	while (sr->nsrt_els_a)
	{
		if ((ft_check_sa(sr, head_a, head_b)) == 1)
			continue;
		if ((ft_check_pa(sr, head_a, head_b)) == 1)
			continue;
		else if ((ft_check_pb(sr, head_a, head_b)) == 1)
			continue;
		else
			ft_check_rr(sr, head_a, head_b);
	}
	while (sr->b_els)
		ft_insert(sr, head_a, head_b);
	ft_finish_sort(sr, head_a, head_b);
	//ft_print_stacks(*head_a, *head_b);//
}
