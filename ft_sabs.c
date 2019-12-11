/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sabs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddarell <ddarell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 23:30:41 by ddarell           #+#    #+#             */
/*   Updated: 2019/12/11 23:30:42 by ddarell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_sa(t_ls **head_a, t_ls **head_b)
{
	t_ls *first;
	t_ls *second;

	head_b = NULL;
	if (!(*head_a))
		return ;
	if ((*head_a)->next == *head_a)
		return ;
	first = *head_a;
	second = first->next;
	if (first->prev != second)
	{
		first->prev->next = second;
		second->next->prev = first;
		first->next = second->next;
		second->prev = first->prev;
		second->next = first;
		first->prev = second;
	}
	*head_a = second;
}

void	ft_sb(t_ls **head_a, t_ls **head_b)
{
	t_ls *first;
	t_ls *second;

	head_a = NULL;
	if (!(*head_b))
		return ;
	if ((*head_b)->next == *head_b)
		return ;
	first = *head_b;
	second = first->next;
	if (first->prev != second)
	{
		first->prev->next = second;
		second->next->prev = first;
		first->next = second->next;
		second->prev = first->prev;
		second->next = first;
		first->prev = second;
	}
	*head_b = second;
}

void	ft_ss(t_ls **head_a, t_ls **head_b)
{
	ft_sa(head_a, head_b);
	ft_sb(head_a, head_b);
}
