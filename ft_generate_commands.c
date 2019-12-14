#include "ps_header.h"

static void check_sorted_data(t_srt_data *srt_data, t_ls *head_a)
{
	t_ls	*head_a_dup;

	head_a_dup = NULL;
	if (!(srt_data->sorted = (int *)malloc(sizeof(int) * srt_data->a_elmnts + 1)))
		ft_error();
	ft_fill_array(srt_data, head_a);
	ft_sort_array(srt_data);
	ft_init_elem_ord(srt_data, head_a);
	head_a_dup = ft_dup_ls(head_a_dup, head_a);
	ft_detect_sorted_data(srt_data, head_a, head_a_dup);
	ft_free_ls(&head_a_dup);
//	free(srt_data->sorted);
//	srt_data->sorted = NULL;
}

void	ft_generate_commands(t_srt_data *srt_data, t_ls **head_a, t_ls **head_b)
{
	check_sorted_data(srt_data, *head_a);
//	check_what_swap(srt_data, *head_a);
//	kick_unsorted_data(srt_data, head_a, head_b);
//	insert_data(srt_data, head_a, head_b);
}
