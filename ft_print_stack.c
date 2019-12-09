#include "checker.h"

void	ft_print_stack(t_ls	*top)
{
	t_ls	*tmp;

	if (!(top))
		return ;
	ft_printf("%d\n", top->numb);
//	if (top == top->next)
//		return ;
	tmp = top->next;
	while (tmp != top)
	{
		ft_printf("%d\n", tmp->numb);
		tmp = tmp->next;
	}
}
