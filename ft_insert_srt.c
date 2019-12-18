#include "ps_header.h"

static int 	count_closest_push(t_ls *head_a, t_ls *head_b, t_ls *b_to_push)
{
	t_ins	ins;
	t_ls	*a_to_get;
	int 	min;
	int		tmp;

	ins.ra = 0;
	ins.rra = 0;
	ins.rb = 0;
	ins.rrb = 0;
	a_to_get = where_push(head_a, b_to_push->numb);
	count_delta(&ins.ra, &ins.rra, head_a, a_to_get);
	count_delta(&ins.rb, &ins.rrb, head_b, b_to_push);
	min = ft_max(ins.ra, ins.rb);
	tmp = ft_max(ins.rra, ins.rrb);
	min = (tmp < min) ? tmp : min;
	tmp = ins.ra + ins.rrb;
	min = (tmp < min) ? tmp : min;
	tmp = ins.rra + ins.rb;
	min = (tmp < min) ? tmp : min;
	return (min);
}

void	ft_insert_srt(t_srt_data *srt_data, t_ls *head_a, t_ls *head_b)
{
	int min;
	int i;
	int tmp;
	t_ls *prev;

	i = 0;
	min = count_closest_push(head_a, head_b, head_b);
	while (i < min)
	{
		tmp = count_closest_push(head_a, head_b, head_b);

		i++;
	}
}
