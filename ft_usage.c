#include "ps_header.h"

void	ft_usage_ps(void)
{
	ft_printf("usage: ./push_swap [-options] <numbers>\n");
	ft_printf("[-v] = visualization\n[-h] = help");
	exit(0);
}

void	ft_usage_ch(void)
{
	ft_printf("usage: ./checker [-options] <numbers> <commands>");
	ft_printf("[-v] = visualization\n[-h] = help");
	exit (0);
}
