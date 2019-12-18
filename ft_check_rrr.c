#include "ps_header.h"

static void	run_rra(t_srt_data *srt_data, t_ls **head_a, t_ls **head_b)
{
	ft_add_command(&srt_data->cm, "rra");
	ft_rra(head_a, head_b);
}

static void	run_rrr(t_srt_data *srt_data, t_ls **head_a, t_ls **head_b)
{
	ft_add_command(&srt_data->cm, "rrr");
	ft_rrr(head_a, head_b);
}

static int rrr_ability(t_ls *head_a, t_ls *head_b)
{
	if (!(head_b) || head_b->next == head_b)
		return (0);
	if ((ft_pa_ability(head_a->prev, head_b)) < (ft_pa_ability(head_a->prev, head_b->prev)))
		return (1);
	return (0);
}

int	ft_check_rrr(t_srt_data *srt_data, t_ls **head_a, t_ls **head_b)
{
	if (!(*head_a) || srt_data->a_els < 2)
		return (0);
	if ((rrr_ability(*head_a, *head_b)) == 1)
	{
		run_rrr(srt_data, head_a, head_b);
		return (1);
	}
	run_rra(srt_data, head_a, head_b);
	return (0);
}
