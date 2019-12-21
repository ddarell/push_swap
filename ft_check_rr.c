#include "ps_header.h"

void	ft_run_rb(t_sr *sr, t_ls **head_a, t_ls **head_b)
{
	ft_add_command(&sr->cm, "rb");
	ft_rb(head_a, head_b);
	sr->ops += 1;
	ft_print_stacks(*head_a, *head_b);//
}

void	ft_run_ra(t_sr *sr, t_ls **head_a, t_ls **head_b)
{
	ft_add_command(&sr->cm, "ra");
	ft_ra(head_a, head_b);
	sr->ops += 1;
	ft_print_stacks(*head_a, *head_b);//
}

void	ft_run_rr(t_sr *sr, t_ls **head_a, t_ls **head_b)
{
	ft_add_command(&sr->cm, "rr");
	ft_rr(head_a, head_b);
	sr->ops += 1;
	ft_print_stacks(*head_a, *head_b);//
}

static int rr_ability(t_ls *head_a, t_ls *head_b)
{
	if (!(head_b) || head_b->next == head_b)
		return (0);
	if ((ft_pa_ability(head_a->next, head_b)) < (ft_pa_ability(head_a->next, head_b->next)))
		return (1);
	return (0);
}

int	ft_check_rr(t_sr *sr, t_ls **head_a, t_ls **head_b)
{
	if (!(*head_a) || sr->a_els < 2)
		return (0);
	if ((rr_ability(*head_a, *head_b)) == 1)
	{
		ft_run_rr(sr, head_a, head_b);
		return (1);
	}
	ft_run_ra(sr, head_a, head_b);
	return (0);
}
