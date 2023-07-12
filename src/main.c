/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverissi <gverissi@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 15:07:21 by gverissi          #+#    #+#             */
/*   Updated: 2023/07/12 22:34:36 by gverissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(Node	*node)
{
	int	size;
	int	tmp;

	size = recursive_length(node);
	if (size > 1)
	{
		tmp = node->value;
		node->value = node->next->value;
		node->next->value = tmp;
	}
}

void	sb(Node *node)
{
	sa(node);
}

void	ss(Node *stack_a, Node *stack_b)
{
	sa(stack_a);
	sa(stack_b);
}

void	pa(Node *stack_a, Node *stack_b)
{
	int	tmp;
	int	counter;

	counter = recursive_length(stack_b);
	if (counter > 0)
	{
		stack_a = insert_at_head(stack_a, stack_b->value);
		stack_b = remove_at_head(stack_b);
	}
}

void	pb(Node *stack_a, Node *stack_b)
{
	int	tmp;
	int	counter;

	counter = recursive_length(stack_a);
	if (counter > 0)
	{
		stack_b = insert_at_head(stack_b, stack_a->value);
		stack_a = remove_at_head(stack_a);
	}
}

/*
int main(void)
{
    Node *stack_a = NULL;
	Node *stack_b = NULL;
	stack_b = insert_at_head(stack_b, 2);
	stack_b = insert_at_head(stack_b, 3);
	stack_b = insert_at_head(stack_b, 9);
	stack_b = insert_at_head(stack_b, 6);
	stack_a = insert_at_head(stack_a, 8);
	stack_a = insert_at_head(stack_a, 1);
    stack_a = insert_at_head(stack_a, 7);
	stack_a = insert_at_head(stack_a, 5);

	printf("\nSTACK A BEFORE\n");
	print_list(stack_a);
	
	printf("\nSTACK B BEFORE\n");
	print_list(stack_b);
	printf("\n\n\n SS stack A and B\n");
	rrr(&stack_a, &stack_b);
	printf("\nSTACK A AFTER\n");
	print_list(stack_a);
	printf("\n\n\nB AFTER\n");
	print_list(stack_b);
	
	
}*/