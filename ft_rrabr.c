/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrabr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddarell <ddarell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 23:30:48 by ddarell           #+#    #+#             */
/*   Updated: 2019/12/11 23:31:16 by ddarell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

void	ft_rra(t_ls **head_a, t_ls **head_b)
{
	head_b = NULL;
	if (*head_a)
		*head_a = (*head_a)->prev;
}

void	ft_rrb(t_ls **head_a, t_ls **head_b)
{
	head_a = NULL;
	if (*head_b)
		*head_b = (*head_b)->prev;
}

void	ft_rrr(t_ls **head_a, t_ls **head_b)
{
	if (*head_a)
		*head_a = (*head_a)->prev;
	if (*head_b)
		*head_b = (*head_b)->prev;
}
