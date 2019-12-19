#include "ps_header.h"

static void	count_a_stack_offset(t_srt_data *srt_data, t_ins *ins, int offset, int right)
{
	if (right)
		ins->ra = offset;
	else
		ins->ra = srt_data->a_els - offset;
	ins->rra = srt_data->a_els - ins->ra;
}

t_ls	*ft_search_a_push_space(t_ls *head_a, t_ls *insert_b, t_ins *ins, t_srt_data *srt_data)
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
		if ((r = ft_pa_ability(next, insert_b)))
			break ;
		if ((l = ft_pa_ability(prev, insert_b)))
			break ;
		next = next->next;
		prev = prev->prev;
		i++;
	}
	if (ins && srt_data)
		count_a_stack_offset(srt_data, ins, i, r);
	return (r == 1 ? next : prev);
}

static int 	min_cm_to_push_rrb(t_ls *head_a, t_ls *head_b, t_ls *insert_b, t_srt_data *srt_data)
{
	t_ins	ins;
	t_ls	*a_to_get;
	int 	min;
	int		tmp;

	ins.rrb = srt_data->ins_of;
	ins.rb = srt_data->b_els - srt_data->ins_of;
	a_to_get = ft_search_a_push_space(head_a, insert_b, &ins, srt_data);
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
	a_to_get = ft_search_a_push_space(head_a, b_to_push, &ins, srt_data);
	min = ft_max(ins.ra, ins.rb);
	tmp = ft_max(ins.rra, ins.rrb);
	min = (tmp < min) ? tmp : min;
	tmp = ins.ra + ins.rrb;
	min = (tmp < min) ? tmp : min;
	tmp = ins.rra + ins.rb;
	min = (tmp < min) ? tmp : min;
	return (min);
}

int	ft_find_insert(t_srt_data *srt_data, t_ls *head_a, t_ls *head_b, t_ls **insert_purpose)
{
	int min;
	int tmp;
	t_ls *prev;
	t_ls *next;

	srt_data->ins_of = 0;
	min = srt_data->a_els + srt_data->b_els + 1;
	prev = head_b;
	next = head_b;
	while (srt_data->ins_of < min && srt_data->ins_of <= (srt_data->b_els / 2))
	{
		tmp = min_cm_to_push_rb(head_a, head_b, next, srt_data);
		if (insert_purpose && tmp < min)
			*insert_purpose = next;
		min = (tmp < min) ? tmp : min;
		if (srt_data->ins_of > 0)
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
