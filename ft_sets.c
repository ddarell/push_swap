#include "checker.h"

void	ft_set_commands(void (**command)(t_ls **, t_ls **))
{
	command[0] = &ft_sa;
	command[1] = &ft_sb;
	command[2] = &ft_ss;
//	command[3] = &ft_pa;
//	command[4] = &ft_pb;
//	command[5] = &ft_ra;
//	command[6] = &ft_rb;
//	command[7] = &ft_rr;
//	command[8] = &ft_rra;
//	command[9] = &ft_rrb;
//	command[10] = &ft_rrr;
}
