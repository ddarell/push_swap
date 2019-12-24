/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddarell <ddarell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 23:33:19 by ddarell           #+#    #+#             */
/*   Updated: 2019/12/11 23:33:23 by ddarell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

void	ft_error(void)
{
	ft_fprintf(2, "Error\n");
	exit(1);
}

void	ft_invalid_option(void)
{
	ft_fprintf(2, "Invalid option\n");
	exit(1);
}

void	ft_no_file(void)
{
	ft_fprintf(2, "Invalid file open\n");
	exit(1);
}
