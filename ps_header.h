/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddarell <ddarell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 23:33:44 by ddarell           #+#    #+#             */
/*   Updated: 2019/12/11 23:39:01 by ddarell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_HEADER_H
# define PS_HEADER_H

# include "ft_printf/ft_printf.h"

typedef	struct	s_ls
{
	struct s_ls	*next;
	struct s_ls	*prev;
	int			numb;
	int 		ord;
	int 		asc;
}				t_ls;

typedef	struct	s_cm
{
	struct s_cm	*next;
	struct s_cm	*prev;
	char cmd[4];
}				t_cm;

typedef	struct	s_srt_data
{
	t_cm		*cm;
	int 		a_elmnts; //number of elmnts in a stack
	int 		b_elmnts; //number of elmnts in b stack
	int 		*sorted;
	int 		sma_a; //smallest order in a
	int			sma_b; //smallest order in b
	int 		big_a; //biggest order in a
	int 		big_b; //biggest order in b
}				t_srt_data;

void			ft_error(void);

void			ft_fill_stack_a(t_ls **head, char **av, int ac);
void			ft_set_commands(void (**command)(t_ls **, t_ls **));
int				ft_get_next_command(int fd, char *cmd);

t_ls			*ft_new_node(int data);
void			ft_add_node_back(t_ls **head, t_ls *node);
void			ft_add_node_top(t_ls **head, t_ls *node);
t_ls			*ft_remove_node(t_ls **head, t_ls *node);

void			ft_sa(t_ls **head_a, t_ls **head_b);
void			ft_sb(t_ls **head_a, t_ls **head_b);
void			ft_ss(t_ls **head_a, t_ls **head_b);
void			ft_pa(t_ls **head_a, t_ls **head_b);
void			ft_pb(t_ls **head_a, t_ls **head_b);
void			ft_ra(t_ls **head_a, t_ls **head_b);
void			ft_rb(t_ls **head_a, t_ls **head_b);
void			ft_rr(t_ls **head_a, t_ls **head_b);
void			ft_rra(t_ls **head_a, t_ls **head_b);
void			ft_rrb(t_ls **head_a, t_ls **head_b);
void			ft_rrr(t_ls **head_a, t_ls **head_b);

void			ft_check_duplicates(t_ls *node, t_ls *head);
int				ft_check_sort(t_ls *top);
void			ft_free_ls(t_ls **top);


void			ft_set_srt_data(t_srt_data *srt_data, t_ls *head_a);

int				ft_count_ls(t_ls *head_a);
void			ft_fill_array(t_srt_data *srt_data, t_ls *head_a);
void			ft_sort_array(t_srt_data *srt_data);
void			ft_init_elem_ord(t_srt_data *srt_data, t_ls *head_a);
void ft_detect_sorted_data(t_srt_data *srt_data, t_ls *top, t_ls *dup);

//int	ft_find_int_tab(int *tab, int num);
//void	ft_add_int_tab(int *tab, t_ls *node, t_ls *top);
int	ft_int_tab_copy(int *dst, int *src);
t_ls *ft_dup_ls(t_ls *dst, t_ls *src);

void	ft_generate_commands(t_srt_data *srt_data, t_ls **head_a, t_ls **head_b);


void			ft_print_stack(t_ls	*top);

#endif
