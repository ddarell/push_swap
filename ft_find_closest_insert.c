#include "ps_header.h"

static void copy_ins(t_ins *dst, t_ins *src)
{
	dst->ins_a = src->ins_a;
	dst->ins_b = src->ins_b;
	dst->ra = src->ra;
	dst->rra = src->rra;
	dst->rb = src->rb;
	dst->rrb = src->rrb;
	dst->ops = src->ops;
	dst->ofs = src->ofs;
}

static void	count_a_stack_offset(t_sr *sr, int offset, int rdir)
{
	if (rdir)
	{
		sr->ins.ra = offset;
		sr->ins.rra = (offset > 0) ? sr->a_els - offset : 0;
	}
	else
	{
		sr->ins.rra = offset;
		sr->ins.ra = (offset > 0) ? sr->a_els - offset : 0;
	}
}

t_ls *ft_search_a_push_space(t_ls *head_a, t_sr *sr)
{
	t_ls *prev;
	t_ls *next;
	int	i;
	int rdir;

	i = 0;
	next = head_a;
	prev = head_a;
	while (1)
	{
		if ((rdir = ft_pa_ability(next, sr->ins.ins_b)))
			break ;
		if (i && ft_pa_ability(prev, sr->ins.ins_b))
			break ;
		next = next->next;
		prev = prev->prev;
		i++;
	}
	count_a_stack_offset(sr, i, rdir);
	return (rdir == 1 ? next : prev);
}

static int 	min_cm_to_push(t_ls *head_a, t_ls *insert_b, t_sr *sr, int rdir)
{
	int ops[4];

	if (rdir)
	{
		sr->ins.rb = sr->ins.ofs;
		sr->ins.rrb = (sr->ins.ofs > 0) ? sr->b_els - sr->ins.ofs : 0;
	}
	else
	{
		sr->ins.rrb = sr->ins.ofs;
		sr->ins.rb = (sr->ins.ofs > 0) ? sr->b_els - sr->ins.ofs : 0;
	}
	sr->ins.ins_b = insert_b;
	sr->ins.ins_a = ft_search_a_push_space(head_a, sr);
	ops[0] = ft_max(sr->ins.ra, sr->ins.rb);
	ops[1] = ft_max(sr->ins.rra, sr->ins.rrb);
	ops[2] = sr->ins.ra + sr->ins.rrb;
	ops[3] = sr->ins.rra + sr->ins.rb;
	sr->ins.ops = ft_seach_min_int(ops, 4);
	return (sr->ins.ops);
}

int ft_find_closest_insert(t_sr *sr, t_ls *head_a, t_ls *head_b)
{
	t_ls *prev;
	t_ls *next;
	t_ins	best;

	ft_set_ins(&best);
	best.ops = sr->a_els + sr->b_els + 1;
	prev = head_b;
	next = head_b;
	while (sr->ins.ofs < best.ops && sr->ins.ofs <= (sr->b_els / 2))
	{
		if (best.ops > (min_cm_to_push(head_a, prev, sr, 0)))
			copy_ins(&best, &sr->ins);
		if (best.ops > (min_cm_to_push(head_a, next, sr, 1)))
			copy_ins(&best, &sr->ins);
		prev = prev->prev;
		next = next->next;
		sr->ins.ofs += 1;
	}
	copy_ins(&sr->ins, &best);
	return (sr->ins.ops);
}
