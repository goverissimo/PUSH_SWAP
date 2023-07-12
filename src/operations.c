/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverissi <gverissi@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 19:17:46 by gverissi          #+#    #+#             */
/*   Updated: 2023/07/12 22:38:53 by gverissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

Node	*ra(Node *node)
{
	Node	*new_node;

	new_node = node;
	new_node = insert_at_tail(new_node, node->value);
	new_node = remove_at_head(new_node);
	return (new_node);
}

Node	*rb(Node *node)

{
	return (ra(node));
}

Node	*rr(Node **stack_a, Node **stack_b)
{
	*stack_a = ra(*stack_a);
	*stack_b = ra(*stack_b);
}

Node	*rra(Node *node)
{
	Node	*new_node;
	Node	*current;
	int		value;

	if (node == NULL)
		return (NULL); 
	else
	{
		current = node;
		while (current->next != NULL)
			current = current->next;
		value = current->value;
	}
	new_node = node;
	new_node = insert_at_head(new_node, value);
	delete_at_tail(new_node);
	return (new_node);
}

Node	*rrb(Node *node)
{
	return (rra(node));
}

