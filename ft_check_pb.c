#include "ps_header.h"

static void	run_pb(t_sr *sr, t_ls **head_a, t_ls **head_b)
{
	ft_add_command(&sr->cm, "pb");
	ft_pb(head_a, head_b);
	sr->ops += 1;
	sr->a_els -= 1;
	sr->b_els += 1;
	sr->nsrt_els_a -= 1;
	(ft_bit_check(sr->fl, VIS)) ? ft_show(sr, *head_a, *head_b, "pb") : 1;
}

static int	pb_ability(t_ls *head_a)
{
	if (!(ft_bit_check(head_a->fl, ORD)))
		return (1);
	return (0);
}

int	ft_check_pb(t_sr *sr, t_ls **head_a, t_ls **head_b)
{
	if (!(*head_a))
		return (0);
	if ((pb_ability(*head_a)) == 1)
	{
		run_pb(sr, head_a, head_b);
		return (1);
	}
	return (0);
}
