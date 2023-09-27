/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pu_ro_rro.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverissi <gverissi@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 15:16:08 by gverissi          #+#    #+#             */
/*   Updated: 2023/09/27 13:34:23 by gverissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push(t_node_list **stack_to, t_node_list **stack_from)
{
	t_node_list	*tmp;
	t_node_list	*head_to;
	t_node_list	*head_from;

	if (list_size(*stack_from) == 0)
		return (-1);
	head_to = *stack_to;
	head_from = *stack_from;
	tmp = head_from;
	head_from = head_from->next;
	*stack_from = head_from;
	if (!head_to)
	{
		head_to = tmp;
		head_to->next = NULL;
		*stack_to = head_to;
	}
	else
	{
		tmp->next = head_to;
		*stack_to = tmp;
	}
	return (0);
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

int	swap(t_node_list	**stack)
{
	t_node_list	*first;
	t_node_list	*second;
	t_node_list	*third;

	if (!*stack || !(*stack)->next)
		return (0);
	first = *stack;
	second = (*stack)->next;
	third = second->next;
	first->next = third;
	second->next = first;
	*stack = second;
	return (1);
}
