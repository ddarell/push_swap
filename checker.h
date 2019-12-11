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

#ifndef CHECKER_H
# define CHECKER_H

# include "ft_printf/ft_printf.h"

typedef	struct	s_ls
{
	struct s_ls	*next;
	struct s_ls	*prev;
	int			numb;
}				t_ls;

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

void			ft_print_stack(t_ls	*top);

#endif
