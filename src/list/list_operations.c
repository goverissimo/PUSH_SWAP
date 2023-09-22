/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverissi <gverissi@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:35:07 by gverissi          #+#    #+#             */
/*   Updated: 2023/09/21 18:32:05 by gverissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int	push(t_node_list **stack_1, t_node_list **stack_2)
{
	t_node_list	*head_1;

	if (!*stack_1)
		return (0);
	head_1 = *stack_1;
	*stack_1 = (*stack_1)->next;
	head_1->next = *stack_2;
	*stack_2 = head_1;
	return (1);
}

int	rotate(t_node_list **stack)
{
	t_node_list	*first;
	t_node_list	*second;
	t_node_list	*last;

	if (!*stack || !(*stack)->next)
		return (0);
	first = *stack;
	second = first->next;
	last = *stack;
	while (last->next)
		last = last->next;
	first->next = NULL;
	last->next = first;
	*stack = second;
	return (1);
}

int	rev_rotate(t_node_list **stack)
{
	t_node_list	*first;
	t_node_list	*last;
	t_node_list	*new_last;

	if (!*stack || !(*stack)->next)
		return (0);
	first = *stack;
	last = *stack;
	while (last->next)
	{
		new_last = last;
		last = last->next;
	}
	new_last->next = NULL;
	last->next = first;
	*stack = last;
	return (1);
}