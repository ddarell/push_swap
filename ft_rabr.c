/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rabr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddarell <ddarell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 23:30:53 by ddarell           #+#    #+#             */
/*   Updated: 2019/12/11 23:31:07 by ddarell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_ra(t_ls **head_a, t_ls **head_b)
{
	head_b = NULL;
	if (*head_a)
		*head_a = (*head_a)->next;
}

void	ft_rb(t_ls **head_a, t_ls **head_b)
{
	head_a = NULL;
	if (*head_b)
		*head_b = (*head_b)->next;
}

void	ft_rr(t_ls **head_a, t_ls **head_b)
{
	if (*head_a)
		*head_a = (*head_a)->next;
	if (*head_b)
		*head_b = (*head_b)->next;
}
