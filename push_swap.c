#include "ps_header.h"

int			main(int ac, char **av)
{
	t_ls *head_a;
	t_ls *head_b;
	t_sr	srt_data;

	head_a = NULL;
	head_b = NULL;
	if (ac < 2)
		return (0);
	ft_fill_stack_a(&head_a, av, ac);
//	if (!(head_a))
//		return (0);
	ft_set_srt_data(&srt_data, head_a);
	ft_generate_commands(&srt_data, &head_a, &head_b);
	ft_free_ls(&head_a);
	ft_free_ls(&head_b);
	return (0);
}
