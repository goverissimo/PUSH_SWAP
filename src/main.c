/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverissi <gverissi@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:10:32 by gverissi          #+#    #+#             */
/*   Updated: 2023/10/04 18:59:15 by gverissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ra(t_node_list **stack_a)
{
	if (rotate(stack_a) == -1)
		return (-1);
	ft_putendl_fd("ra", 1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_node_list	*stack_a;
	t_node_list	*stack_b;

	if (argc < 2)
		return (-1);
	ft_check_args(argc, argv);
	stack_a = NULL;
	stack_b = NULL;
	ft_init_stack(&stack_a, argc, argv);
	if (is_sorted(&stack_a))
	{
		ft_free_stack(&stack_a);
		return (0);
	}
	sort_stacks(&stack_a, &stack_b);
	ft_free_stack(&stack_a);
	ft_free_stack(&stack_b);
	return (0);
}
