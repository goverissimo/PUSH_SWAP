/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverissi <gverissi@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:20:33 by gverissi          #+#    #+#             */
/*   Updated: 2023/10/04 18:58:57 by gverissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**initialize_args(int argc, char **argv, int *should_free_args, int *i)
{
	char	**args;

	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		*should_free_args = 1;
		*i = 0;
	}
	else
	{
		args = argv;
		*i = 1;
	}
	return (args);
}

void	ft_check_args(int argc, char **argv)
{
	int		i;
	long	tmp;
	char	**args;
	int		should_free_args;

	should_free_args = 0;
	args = initialize_args(argc, argv, &should_free_args, &i);
	while (args[i])
	{
		tmp = ft_atoi(args[i]);
		if (!ft_isnum(args[i]) || ft_contains(tmp, args, i) || \
		tmp < INT_MIN || tmp > INT_MAX)
		{
			if (should_free_args) 
				ft_free_list(args);
			ft_error("Error");
		}
		i++;
	}
	if (should_free_args)
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
