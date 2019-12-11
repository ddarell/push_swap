/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_n_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddarell <ddarell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 23:33:28 by ddarell           #+#    #+#             */
/*   Updated: 2019/12/11 23:33:35 by ddarell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_check_duplicates(t_ls *node, t_ls *head)
{
	int	num;

	num = node->numb;
	if (node == head)
		return ;
	while (node != head)
	{
		node = node->prev;
		if (node->numb == num)
			ft_error();
	}
}

int		ft_check_sort(t_ls *top)
{
	int		num;
	t_ls	*tmp;

	if (!top)
		return (0);
	num = top->numb;
	tmp = top->next;
	while (tmp != top)
	{
		if (num > tmp->numb)
			return (0);
		num = tmp->numb;
		tmp = tmp->next;
	}
	return (1);
}

void	ft_free_ls(t_ls **top)
{
	t_ls *front;
	t_ls *back;

	if (!(*top))
		return ;
	(*top)->prev->next = NULL;
	(*top)->prev = NULL;
	back = *top;
	front = (*top)->next;
	free(back);
	while (front)
	{
		back = front;
		front = front->next;
		free(back);
	}
	*top = NULL;
}
