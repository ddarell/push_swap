/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pab.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddarell <ddarell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 23:32:11 by ddarell           #+#    #+#             */
/*   Updated: 2019/12/11 23:32:12 by ddarell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

void	ft_pa(t_ls **head_a, t_ls **head_b)
{
	t_ls	*node;

	node = ft_remove_node(head_b, *head_b);
	ft_add_node_top(head_a, node);
}

void	ft_pb(t_ls **head_a, t_ls **head_b)
{
	t_ls	*node;

	node = ft_remove_node(head_a, *head_a);
	ft_add_node_top(head_b, node);
}
