#include "checker.h"

t_ls	*ft_add_node(t_ls *node, int data)
{
	t_ls	*new_node;

	new_node = (t_ls *)malloc(sizeof(t_ls));
	if (new_node == NULL)
		ft_error();
	new_node->numb = data;
	new_node->next = NULL;
	new_node->prev = node;
	if (node)
		node->next = new_node;
	return (new_node);
}
