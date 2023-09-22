/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverissi <gverissi@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:39:59 by gverissi          #+#    #+#             */
/*   Updated: 2023/09/21 21:33:13 by gverissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
void make_index(t_node_list **node_list)
{
    t_node_list	*head;
	t_node_list *current;
	t_node_list	*aux;
	int	index;

	head = *node_list;
	current = *node_list;
	aux = head;

	while (current)
	{
		index = 0;
		while(head)
		{
			if (current->value > head->value)
				index++;
			head = head->next;
		}
		current->index = index;
		current = current->next;
		head = aux;
	}
}

void sort_stacks(t_node_list **stack_a, t_node_list **stack_b)
{
	int	size;

	size = list_size(*stack_a);
	index(stack_a);
	if (size <= 5)
		printf("hello");
	else
    	radix_sort(stack_a, stack_b);
	
}