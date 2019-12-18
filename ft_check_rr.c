#include "ps_header.h"

static void	run_ra(t_srt_data *srt_data, t_ls **head_a, t_ls **head_b)
{
	ft_add_command(&srt_data->cm, "ra");
	ft_ra(head_a, head_b);
}

static void	run_rr(t_srt_data *srt_data, t_ls **head_a, t_ls **head_b)
{
	ft_add_command(&srt_data->cm, "rr");
	ft_rr(head_a, head_b);
}

static int rr_ability(t_ls *head_a, t_ls *head_b)
{
	if (!(head_b) || head_b->next == head_b)
		return (0);
	if ((ft_pa_ability(head_a->next, head_b)) < (ft_pa_ability(head_a->next, head_b->next)))
		return (1);
	return (0);
}

int	ft_check_rr(t_srt_data *srt_data, t_ls **head_a, t_ls **head_b)
{
	if (!(*head_a) || srt_data->a_els < 2)
		return (0);
	if ((rr_ability(*head_a, *head_b)) == 1)
	{
		run_rr(srt_data, head_a, head_b);
		return (1);
	}
	run_ra(srt_data, head_a, head_b);
	return (0);
}
