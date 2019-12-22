/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddarell <ddarell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 23:33:44 by ddarell           #+#    #+#             */
/*   Updated: 2019/12/22 23:21:17 by ddarell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_HEADER_H
# define PS_HEADER_H

# include "ft_printf/ft_printf.h"

# define ORD 0
# define LDIR 1
# define INS 2

typedef	struct	s_ls
{
	struct s_ls	*next;
	struct s_ls	*prev;
	int			numb;
	int			fl;
}				t_ls;

typedef	struct	s_ins
{	t_ls		*ins_a;
	t_ls		*ins_b;
	int			ra;
	int			rra;
	int			rb;
	int			rrb;
	int			rr;
	int			rrr;
	int			ops;
	int			ofs;
}				t_ins;

typedef	struct	s_cm
{
	struct s_cm	*next;
	char		cmd[4];
}				t_cm;

typedef	struct	s_sr
{
	t_cm		*cm;
	int			a_els;
	int			b_els;
	int			srt_els_a;
	int			nsrt_els_a;
	int			*sorted;
	t_ins		ins;
	int			ops;
}				t_sr;

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

void			ft_set_srt_data(t_sr *sr, t_ls *head_a);
void			ft_set_ins(t_ins *ins);

int				ft_count_ls(t_ls *head_a);
void			ft_fill_array(t_sr *sr, t_ls *head_a);
void			ft_sort_array(t_sr *sr);
void			ft_init_elem_ord(t_sr *sr, t_ls *head_a);
void			ft_detect_sorted_data(t_sr *sr, t_ls *top, t_ls **dup);

//int			ft_find_int_tab(int *tab, int num);
//void			ft_add_int_tab(int *tab, t_ls *node, t_ls *top);
int				ft_int_tab_copy(int *dst, int *src);
t_ls			*ft_dup_ls(t_ls *dst, t_ls *src);
t_ls			*ft_search_ls_num(t_ls *top, int num);
t_ls			*ft_search_ls_fl(t_ls *top, int fl);

void			ft_generate_commands(t_sr *sr, t_ls **head_a, t_ls **head_b);

int				ft_check_pa(t_sr *sr, t_ls **head_a, t_ls **head_b);
int				ft_pa_ability(t_ls *head_a, t_ls *head_b);

//int			ft_check_pa(t_sr *srt_data, t_ls **head_a, t_ls **head_b);
void			ft_add_command(t_cm **cm, char *str);
int				ft_check_pb(t_sr *sr, t_ls **head_a, t_ls **head_b);
int				ft_check_rr(t_sr *sr, t_ls **head_a, t_ls **head_b);
int				ft_check_rrr(t_sr *sr, t_ls **head_a, t_ls **head_b);
int				ft_check_sa(t_sr *sr, t_ls **head_a, t_ls **head_b);

void			ft_insert(t_sr *sr, t_ls **head_a, t_ls **head_b);
int				ft_find_closest_insert(t_sr *sr, t_ls *head_a, t_ls *head_b);
t_ls			*ft_search_a_push_space(t_ls *head_a, t_sr *sr);

void			ft_run_ra(t_sr *sr, t_ls **head_a, t_ls **head_b);
void			ft_run_rb(t_sr *sr, t_ls **head_a, t_ls **head_b);
void			ft_run_rr(t_sr *sr, t_ls **head_a, t_ls **head_b);
void			ft_run_rra(t_sr *sr, t_ls **head_a, t_ls **head_b);
void			ft_run_rrb(t_sr *sr, t_ls **head_a, t_ls **head_b);
void			ft_run_rrr(t_sr *sr, t_ls **head_a, t_ls **head_b);
void			ft_finish_sort(t_sr *sr, t_ls **head_a, t_ls **head_b);

void			ft_print_stack(t_ls	*top);
void			ft_print_stacks(t_ls *head_a, t_ls *head_b);

#endif
