#include "ps_header.h"

void	ft_run_rrb(t_sr *sr, t_ls **head_a, t_ls **head_b)
{
	ft_add_command(&sr->cm, "rrb");
	ft_rrb(head_a, head_b);
	sr->ops += 1;
	ft_print_stacks(*head_a, *head_b);//
}

void	ft_run_rra(t_sr *sr, t_ls **head_a, t_ls **head_b)
{
	ft_add_command(&sr->cm, "rra");
	ft_rra(head_a, head_b);
	sr->ops += 1;
	ft_print_stacks(*head_a, *head_b);//
}

void	ft_run_rrr(t_sr *sr, t_ls **head_a, t_ls **head_b)
{
	ft_add_command(&sr->cm, "rrr");
	ft_rrr(head_a, head_b);
	sr->ops += 1;
	ft_print_stacks(*head_a, *head_b);//
}

static int rrr_ability(t_ls *head_a, t_ls *head_b)
{
	if (!(head_b) || head_b->next == head_b)
		return (0);
	if ((ft_pa_ability(head_a->prev, head_b)) < (ft_pa_ability(head_a->prev, head_b->prev)))
		return (1);
	return (0);
}

int	ft_check_rrr(t_sr *sr, t_ls **head_a, t_ls **head_b)
{
	if (!(*head_a) || sr->a_els < 2)
		return (0);
	if ((rrr_ability(*head_a, *head_b)) == 1)
	{
		ft_run_rrr(sr, head_a, head_b);
		return (1);
	}
	ft_run_rra(sr, head_a, head_b);
	return (0);
}
