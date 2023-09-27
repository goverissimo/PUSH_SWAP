/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sorting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverissi <gverissi@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 15:26:08 by gverissi          #+#    #+#             */
/*   Updated: 2023/09/27 13:32:42 by gverissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_distance(t_node_list **stack, int index)
{
	t_node_list	*head;
	int			distance;

	distance = 0;
	head = *stack;
	while (head)
	{
		if (head->index == index)
			break ;
		distance++;
		head = head->next;
	}
	return (distance);
}

int	get_min(t_node_list **stack, int val)
{
	t_node_list	*head;
	int			min;

	head = *stack;
	min = head->index;
	while (head->next)
	{
		head = head->next;
		if ((head->index < min) && head->index != val)
			min = head->index;
	}
	return (min);
}

void	sort_3(t_node_list **stack_a)
{
	if (is_sorted(stack_a))
		return ;
	if ((*stack_a)->value > (*stack_a)->next->value && \
		(*stack_a)->value > (*stack_a)->next->next->value)
	{
		ra(stack_a);
		if ((*stack_a)->next->value < (*stack_a)->next->next->value \
			&& !is_sorted(stack_a))
			sa(stack_a);
		return ;
	}
	if (((*stack_a)->value < (*stack_a)->next->value) && \
		((*stack_a)->next->value > (*stack_a)->next->next->value) \
			&& !is_sorted(stack_a))
	{
		rra(stack_a);
		if ((*stack_a)->next->value < (*stack_a)->next->next->value \
			&& !is_sorted(stack_a))
			sa(stack_a);
		return ;
	}
	sa(stack_a);
}

void	sort_4(t_node_list **stack_a, t_node_list **stack_b)
{
	int	distance;

	if (is_sorted(stack_a))
		return ;
	distance = get_distance(stack_a, get_min(stack_a, -1));
	if (distance == 1)
		ra(stack_a);
	else if (distance == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (distance == 3)
		rra(stack_a);
	if (is_sorted(stack_a))
		return ;
	pb(stack_a, stack_b);
	sort_3(stack_a);
	pa(stack_a, stack_b);
}

void	sort_5(t_node_list **stack_a, t_node_list **stack_b)
{
	int	distance;

	distance = get_distance(stack_a, get_min(stack_a, -1));
	if (distance == 1)
		ra(stack_a);
	else if (distance == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (distance == 3)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if (distance == 4)
		rra(stack_a);
	if (is_sorted(stack_a))
		return ;
	pb(stack_a, stack_b);
	sort_4(stack_a, stack_b);
	pa(stack_a, stack_b);
}
