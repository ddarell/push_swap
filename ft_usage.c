/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usage.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddarell <ddarell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 18:21:35 by ddarell           #+#    #+#             */
/*   Updated: 2019/12/24 18:21:41 by ddarell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	exit(0);
}
