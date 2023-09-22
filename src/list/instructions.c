/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverissi <gverissi@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:20:39 by gverissi          #+#    #+#             */
/*   Updated: 2023/09/21 18:35:07 by gverissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "list.h"

int	rrb(t_node_list **stack_a, t_node_list **stack_b)
{
	return (rev_rotate(stack_a) && rev_rotate(stack_b));
}

int	rb(t_node_list **stack_a, t_node_list **stack_b)
{
	return (rotate(stack_a) && rotate(stack_b));
}


int	sb(t_node_list **stack_a, t_node_list **stack_b)
{
	return (swap(stack_a) && swap(stack_b));
}

int	exec_rotate(char *ptr, t_node_list **stack_a, t_node_list **stack_b, int size)
{
	if (!ft_strncmp("ra", ptr, size))
		return (rotate(stack_a));
	if (!ft_strncmp("rb", ptr, size))
		return (rotate(stack_b));
	if (!ft_strncmp("rr", ptr, size))
		return (rb(stack_a, stack_b));
	if (!ft_strncmp("rra", ptr, size))
		return (rev_rotate(stack_a));
	if (!ft_strncmp("rrb", ptr, size))
		return (rev_rotate(stack_b));
	if (!ft_strncmp("rrr", ptr, size))
		return (rrb(stack_a, stack_b));
	return (0);
}

void	execute_move(char *ptr, t_node_list **stack_a, t_node_list **stack_b)
{
	int	size;
	int	sucess;

	size = ft_strlen(ptr);
	if (ptr[0] == 'r')
		sucess = exec_rotate(ptr, stack_a, stack_b, size);
	if (!ft_strncmp("sa", ptr, size))
		sucess = swap(stack_a);
	if (!ft_strncmp("sb", ptr, size))
		sucess = swap(stack_b);
	if (!ft_strncmp("ss", ptr, size))
		sucess = swap_both(stack_a, stack_b);
	if (!ft_strncmp("pa", ptr, size))
		sucess = push(stack_b, stack_a);
	if (!ft_strncmp("pb", ptr, size))
		sucess = push(stack_a, stack_b);
	if (sucess)
	{
		write (1, ptr, size);
		write (1, "\n", 1);
	}
}