#include "ps_header.h"

static void	run_operations(t_srt_data *srt_data, t_ls **head_a, t_ls **head_b, t_ins *ins)
{
	int i;

	i = 0;
	while (++i <= ins->rr)
		ft_run_rr(srt_data, head_a, head_b);
	i = 0;
	while (++i <= ins->ra)
		ft_run_ra(srt_data, head_a, head_b);
	i = 0;
	while (++i <= ins->rb)
		ft_run_rb(srt_data, head_a, head_b);
	i = 0;
	while (++i <= ins->rrr)
		ft_run_rrr(srt_data, head_a, head_b);
	i = 0;
	while (++i <= ins->rra)
		ft_run_rra(srt_data, head_a, head_b);
	i = 0;
	while (++i <= ins->rrb)
		ft_run_rrb(srt_data, head_a, head_b);
	ft_check_pa(srt_data, head_a, head_b);
}

static void	set_rr_rrr(t_ins *ins, int flag)
{
	if (flag == 0)
	{
		while (ins->ra && ins->rb)
		{
			ins->ra -= 1;
			ins->rb -= 1;
			ins->rr += 1;
		}
		ins->rrb = 0;
		ins->rra = 0;
	}
	else if (flag == 1)
	{
		while (ins->rra && ins->rrb)
		{
			ins->rra -= 1;
			ins->rrb -= 1;
			ins->rrr += 1;
		}
		ins->rb = 0;
		ins->ra = 0;
	}
}

static void	count_operations(t_ins *ins)
{	int ops[4];
	int flag;

	ins->rr = 0;
	ins->rrr = 0;
	ops[0] = ft_max(ins->ra, ins->rb);
	ops[1] = ft_max(ins->rra, ins->rrb);
	ops[2] = ins->ra + ins->rrb;
	ops[3] = ins->rra + ins->rb;
	flag = ft_search_int_tab(ops, 4, ft_seach_min_int(ops, 4));
	if (flag == 0 || flag == 1)
		set_rr_rrr(ins, flag);
	else if (flag == 2)
	{
		ins->rra = 0;
		ins->rb = 0;
	}
	else if (flag == 3)
	{
		ins->ra = 0;
		ins->rrb = 0;
	}
}

static void	count_b_stack_offset(t_ls *head_b, t_ls *insert_b, t_srt_data *srt_data, t_ins *ins)
{
	t_ls *prev;
	t_ls *next;

	srt_data->ins_of = 0;
	prev = head_b;
	next = head_b;
	while (prev != insert_b && next != insert_b)
	{
		next = next->next;
		prev = prev->prev;
		srt_data->ins_of += 1;
	}
	ins->rb = (next == insert_b) ? srt_data->ins_of : srt_data->b_els - srt_data->ins_of;
	ins->rrb = srt_data->b_els - ins->rb;
}

void	ft_insert(t_srt_data *srt_data, t_ls **head_a, t_ls **head_b)
{
	t_ls *insert_a;
	t_ls *insert_b;
	t_ins ins;

	ft_find_insert(srt_data, *head_a, *head_b, &insert_b);
	insert_a = ft_search_a_push_space(*head_a, insert_b, &ins, srt_data);
	ft_bit_on(&insert_a->fl, INS);
	ft_bit_on(&insert_b->fl, INS);
	count_b_stack_offset(*head_b, insert_b, srt_data, &ins);
	count_operations(&ins);
	run_operations(srt_data, head_a, head_b, &ins);
	ft_bit_off(&insert_a->fl, INS);
	ft_bit_off(&insert_b->fl, INS);
}
