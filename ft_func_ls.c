/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_ls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddarell <ddarell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 23:33:28 by ddarell           #+#    #+#             */
/*   Updated: 2019/12/24 18:29:04 by ddarell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

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

int		ft_count_ls(t_ls *head_a)
{
	int		i;
	t_ls	*tmp;

	if (!(head_a))
		return (0);
	i = 1;
	tmp = head_a->next;
	while (tmp != head_a)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

t_ls	*ft_dup_ls(t_ls *dst, t_ls *src)
{
	t_ls	*node;
	t_ls	*tmp;

	if (!(src))
		return (NULL);
	node = ft_new_node(src->numb);
	ft_add_node_back(&dst, node);
	tmp = src->next;
	while (tmp != src)
	{
		node = ft_new_node(tmp->numb);
		ft_add_node_back(&dst, node);
		tmp = tmp->next;
	}
	return (dst);
}
