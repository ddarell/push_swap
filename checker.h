#ifndef _CHECKER_H
#define _CHECKER_H

# include "ft_printf/ft_printf.h"

typedef	struct	s_ls
{
	struct s_ls	*next;
	struct s_ls	*prev;
	int	lli;
}				t_ls;

void	ft_error(void);
void	ft_set_ls(t_ls **head, char	*str);

#endif
