/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_commant_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddarell <ddarell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 18:31:26 by ddarell           #+#    #+#             */
/*   Updated: 2019/12/24 18:32:02 by ddarell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

static void	add_command_back(t_cm **head, t_cm *node)
{
	t_cm *tmp;

	if (!(node))
		return ;
	if (!(*head))
	{
		*head = node;
		return ;
	}
	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
}

static t_cm	*new_command(char *str)
{
	t_cm	*new_node;

	new_node = (t_cm *)malloc(sizeof(t_cm));
	if (new_node == NULL)
		ft_error();
	ft_strcpy(new_node->cmd, str);
	new_node->next = NULL;
	return (new_node);
}

void		ft_add_command(t_cm **cm, char *str)
{
	t_cm *tmp;

	tmp = new_command(str);
	add_command_back(cm, tmp);
}
