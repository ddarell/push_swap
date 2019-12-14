/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nodes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddarell <ddarell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 23:32:19 by ddarell           #+#    #+#             */
/*   Updated: 2019/12/11 23:32:27 by ddarell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

t_ls	*ft_new_node(int data)
{
	t_ls	*new_node;

	new_node = (t_ls *)malloc(sizeof(t_ls));
	if (new_node == NULL)
		ft_error();
	new_node->numb = data;
	new_node->ord = -1;
	new_node->asc = 0;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

void	ft_add_node_back(t_ls **head, t_ls *node)
{
	t_ls *last_node;

	if (!(node))
		return ;
	if (!(*head))
	{
		*head = node;
		node->next = node;
		node->prev = node;
		return ;
	}
	last_node = (*head)->prev;
	last_node->next = node;
	(*head)->prev = node;
	node->next = *head;
	node->prev = last_node;
}

void	ft_add_node_top(t_ls **head, t_ls *node)
{
	if (!(node))
		return ;
	ft_add_node_back(head, node);
	*head = (*head)->prev;
}

t_ls	*ft_remove_node(t_ls **head, t_ls *node)
{
	if (!(*head || node))
		return (NULL);
	if (node->next == node)
	{
		*head = NULL;
		node->next = NULL;
		node->prev = NULL;
		return (node);
	}
	if (node == *head)
		(*head) = node->next;
	node->prev->next = node->next;
	node->next->prev = node->prev;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}
