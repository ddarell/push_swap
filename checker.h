#ifndef _CHECKER_H
#define _CHECKER_H

# include "ft_printf/ft_printf.h"

typedef	struct	s_ls
{
	struct s_ls	*next;
	struct s_ls	*prev;
	int			numb;
}				t_ls;

void	ft_error(void);
void ft_fill_a(t_ls **head, char **av, int ac);
t_ls *ft_new_node(int data);
void	ft_add_node_back(t_ls **head, t_ls *node);
void	ft_print_stack(t_ls	*top);
void	ft_check_duplicates(t_ls *node, t_ls *head);
void	ft_set_commands(void (**command)(t_ls **, t_ls **));

void	ft_sa(t_ls **head_a, t_ls **head_b);
void	ft_sb(t_ls **head_a, t_ls **head_b);
void	ft_ss(t_ls **head_a, t_ls **head_b);

#endif
