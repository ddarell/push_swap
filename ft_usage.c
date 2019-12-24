/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usage.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddarell <ddarell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 18:21:35 by ddarell           #+#    #+#             */
/*   Updated: 2019/12/24 21:47:28 by ddarell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

void	ft_usage_ps(void)
{
	ft_printf("usage: ./push_swap [-options] numbers_list ...\n");
	ft_printf("[-v] = debug\n[-h] = help\n");
	ft_printf("[-f <file_path>] = put result in file\n");
	exit(0);
}

void	ft_usage_ch(void)
{
	ft_printf("usage: ./checker [-options] numbers_list ... ps_command ...\n");
	ft_printf("[-v] = debug\n[-h] = help\n");
	ft_printf("[-f <file_path>] = read commands from file\n\n");
	ft_printf("valid commands: sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr");
	ft_printf("\n");
	exit(0);
}
