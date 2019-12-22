#include "ps_header.h"

static void	print_commands(t_cm *cm)
{
	while (cm)
	{
		ft_printf("%s\n", cm->cmd);
		cm = cm->next;
	}
}

static void	free_cm(t_cm **cm)
{
	t_cm *front;
	t_cm *back;

	if (!(*cm))
		return ;
	back = *cm;
	front = (*cm)->next;
	free(back);
	while (front)
	{
		back = front;
		front = front->next;
		free(back);
	}
	*cm = NULL;
}

int			main(int ac, char **av)
{
	t_ls *head_a;
	t_ls *head_b;
	t_sr	sr;

	head_a = NULL;
	head_b = NULL;
	if (ac < 2)
		return (0);
	ft_fill_stack_a(&head_a, av, ac);
	ft_set_srt_data(&sr, head_a);
	ft_generate_commands(&sr, &head_a, &head_b);
	print_commands(sr.cm);
	free_cm(&sr.cm);
	ft_free_ls(&head_a);
	ft_free_ls(&head_b);
	return (0);
}
