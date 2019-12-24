/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_option.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddarell <ddarell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 18:39:52 by ddarell           #+#    #+#             */
/*   Updated: 2019/12/24 18:39:59 by ddarell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

int	ft_check_options(char **av, int *ac, int *fl)
{
	int	i;
	int j;

	i = 1;
	*fl = 0;
	while (i < *ac && av[i][0] == '-' && (av[i][1] > '9' || av[i][1] < '0'))
	{
		j = 1;
		while (av[i][j] == 'v' || av[i][j] == 'h' || av[i][j] == 'f')
		{
			(av[i][j] == 'v') ? ft_bit_on(fl, VIS) : 1;
			(av[i][j] == 'h') ? ft_usage_ps() : 1;
			(av[i][j] == 'f') ? ft_bit_on(fl, FRD) : 1;
			j++;
		}
		if (av[i][j])
			ft_invalid_option();
		i++;
	}
	*ac = *ac - (i - 1);
	return (i - 1);
}
