/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverissi <gverissi@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:20:33 by gverissi          #+#    #+#             */
/*   Updated: 2023/09/27 16:13:42 by gverissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_args(int argc, char **argv)
{
	int		i;
	long	tmp;
	char	**args;	

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		tmp = ft_atoi(args[i]);
		if (!ft_isnum(args[i]))
			ft_error("Error");
		if (ft_contains(tmp, args, i))
			ft_error("Error");
		if (tmp < INT_MIN || tmp > INT_MAX)
			ft_error("Error");
		i++;
	}
	if (argc == 2)
		ft_free_list(args);
}

void	sort_stacks(t_node_list **stack_a, t_node_list **stack_b)
{
	int	size;

	size = list_size(*stack_a);
	if (size <= 5)
		simple_sort(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
}

void	simple_sort(t_node_list **stack_a, t_node_list **stack_b)
{
	int	size;

	if (is_sorted(stack_a) || list_size(*stack_a) == 0
		|| list_size(*stack_a) == 1)
		return ;
	size = list_size(*stack_a);
	if (size == 2)
		sa(stack_a);
	else if (size == 3)
		sort_3(stack_a);
	else if (size == 4)
		sort_4(stack_a, stack_b);
	else if (size == 5)
		sort_5(stack_a, stack_b);
}

int	ra(t_node_list **stack_a)
{
	if (rotate(stack_a) == -1)
		return (-1);
	ft_putendl_fd("ra", 1);
	return (0);
}

void	radix_sort(t_node_list **stack_a, t_node_list **stack_b)
{
	int		i;
	int		j;
	int		size;
	int		max_bits;

	i = 0;
	max_bits = 0;
	size = list_size(*stack_a);
	while (((size - 1) >> max_bits) != 0)
		++max_bits;
	while (i < max_bits)
	{
		j = 0;
		while (j < size) 
		{
			if ((((*stack_a)->index) >> i) & 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
			j++;
		}
		while (*stack_b)
			pa(stack_a, stack_b);
		i++;
	}
}
