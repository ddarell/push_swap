#include "checker.h"

t_ls *ft_new_node(int data)
{
	t_ls	*new_node;

	new_node = (t_ls *)malloc(sizeof(t_ls));
	if (new_node == NULL)
		ft_error();
	new_node->numb = data;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

void	ft_add_node_back(t_ls **head, t_ls *node)
{
	t_ls *back_node;

	if (!(*head))
	{
		*head = node;
		node->next = node;
		node->prev = node;
		return ;
	}
	back_node = (*head)->prev;
	back_node->next = node;
	(*head)->prev = node;
	node->next = *head;
	node->prev = back_node;
}

void	ft_add_node_top(t_ls **head, t_ls *node)
{
	return ;
}

t_ls	*ft_remove_node(t_ls **head, t_ls *node)
{
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
