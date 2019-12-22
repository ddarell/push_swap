#include "ps_header.h"

static void	run_operations(t_sr *sr, t_ls **head_a, t_ls **head_b)
{
	int i;

	i = 0;
	while (++i <= sr->ins.rr)
		ft_run_rr(sr, head_a, head_b);
	i = 0;
	while (++i <= sr->ins.ra)
		ft_run_ra(sr, head_a, head_b);
	i = 0;
	while (++i <= sr->ins.rb)
		ft_run_rb(sr, head_a, head_b);
	i = 0;
	while (++i <= sr->ins.rrr)
		ft_run_rrr(sr, head_a, head_b);
	i = 0;
	while (++i <= sr->ins.rra)
		ft_run_rra(sr, head_a, head_b);
	i = 0;
	while (++i <= sr->ins.rrb)
		ft_run_rrb(sr, head_a, head_b);
	ft_check_pa(sr, head_a, head_b);
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
{
	int flag;

	flag = -1;
	if (ins->ops == ft_max(ins->ra, ins->rb))
		flag = 0;
	else if (ins->ops == ft_max(ins->rra, ins->rrb))
		flag = 1;
	else if (ins->ops == ins->ra + ins->rrb)
		flag = 2;
	else if (ins->ops == ins->rra + ins->rb)
		flag = 3;
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

void	ft_insert(t_sr *sr, t_ls **head_a, t_ls **head_b)
{
	ft_set_ins(&sr->ins);
	ft_find_closest_insert(sr, *head_a, *head_b);
	ft_bit_on(&sr->ins.ins_a->fl, INS);
	ft_bit_on(&sr->ins.ins_b->fl, INS);
//	ft_print_stacks(*head_a, *head_b);//
	count_operations(&sr->ins);
	run_operations(sr, head_a, head_b);
	ft_bit_off(&sr->ins.ins_a->fl, INS);
	ft_bit_off(&sr->ins.ins_b->fl, INS);
}
