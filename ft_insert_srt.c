#include "ps_header.h"

static void	count_delta(t_ins *ins, t_ls *head_a, t_ls *dst)
{
	t_ls *prev;
	t_ls *next;
	int i

	if (head_a == dst)
	{
		ins->ra = 0;
		ins->rb = 0;
		return ;
	}
	next = head_a->next;
	prev = head_a->prev;
	while (1)
	{
		if (ft_pa_ability(next, b_to_push))
			return (next);
		if (ft_pa_ability(prev, b_to_push))
			return (prev);
		next = next->next;
		prev = prev->prev;
	}

}

static t_ls	*where_push(t_ls *head_a, t_ls *b_to_push, int *ra, int *rra)
{
	t_ls *prev;
	t_ls *next;
	int	i;
	int r;
	int l;

	i = 0;
	next = head_a;
	prev = head_a;
	while (1)
	{
		if ((r = ft_pa_ability(next, b_to_push)))
			break ;
		if ((l = ft_pa_ability(prev, b_to_push)))
			break ;
		next = next->next;
		prev = prev->prev;
		i++;
	}
	count_delta(ra, rra, i, r);
	return (r == 1 ? next : prev);
}

static int 	min_cm_to_push_rrb(t_ls *head_a, t_ls *head_b, t_ls *b_to_push, t_srt_data *srt_data)
{
	t_ins	ins;
	t_ls	*a_to_get;
	int 	min;
	int		tmp;

	ins.rrb = srt_data->ins_of;
	ins.rb = srt_data->b_els - srt_data->ins_of;
	a_to_get = where_push(head_a, b_to_push, &ins.ra, &ins.rra);
//	count_delta(&ins, head_a, a_to_get);
//	count_delta(&ins.rb, &ins.rrb, head_b, b_to_push);
	min = ft_max(ins.ra, ins.rb);
	tmp = ft_max(ins.rra, ins.rrb);
	min = (tmp < min) ? tmp : min;
	tmp = ins.ra + ins.rrb;
	min = (tmp < min) ? tmp : min;
	tmp = ins.rra + ins.rb;
	min = (tmp < min) ? tmp : min;
	return (min);
}

static int 	min_cm_to_push_rb(t_ls *head_a, t_ls *head_b, t_ls *b_to_push, t_srt_data *srt_data)
{
	t_ins	ins;
	t_ls	*a_to_get;
	int 	min;
	int		tmp;

	ins.rb = srt_data->ins_of;
	ins.rrb = srt_data->b_els - srt_data->ins_of;
	a_to_get = where_push(head_a, b_to_push);
	count_delta(&ins.ra, &ins.rra, head_a, a_to_get);
//	count_delta(&ins.rb, &ins.rrb, head_b, b_to_push);
	min = ft_max(ins.ra, ins.rb);
	tmp = ft_max(ins.rra, ins.rrb);
	min = (tmp < min) ? tmp : min;
	tmp = ins.ra + ins.rrb;
	min = (tmp < min) ? tmp : min;
	tmp = ins.rra + ins.rb;
	min = (tmp < min) ? tmp : min;
	return (min);
}

int	ft_insert_srt(t_srt_data *srt_data, t_ls *head_a, t_ls *head_b, t_ls **insert_purpose)
{
	int min;
	int tmp;
	t_ls *prev;
	t_ls *next;

	srt_data->ins_of = 0;
	min = min_cm_to_push_rb(head_a, head_b, head_b, srt_data);
	if (insert_purpose)
		*insert_purpose = head_b;
	prev = head_b->prev;
	next = head_b->next;
	srt_data->ins_of += 1;
	while (srt_data->ins_of < min && srt_data->ins_of < (srt_data->b_els / 2))
	{
		tmp = min_cm_to_push_rb(head_a, head_b, next, srt_data);
		if (insert_purpose && tmp < min)
			*insert_purpose = next;
		min = (tmp < min) ? tmp : min;
		tmp = min_cm_to_push_rrb(head_a, head_b, prev, srt_data);
		min = (tmp < min) ? tmp : min;
		if (insert_purpose && tmp < min)
			*insert_purpose = prev;
		prev = prev->prev;
		next = next->next;
		srt_data->ins_of += 1;
	}
	return (min);
}
