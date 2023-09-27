/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverissi <gverissi@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:39:24 by gverissi          #+#    #+#             */
/*   Updated: 2023/09/27 15:34:16 by gverissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "utils.h"
# include "../libft/libft.h"

/*INT MAX & MIN*/
# define INT_MAX 2147483647
# define INT_MIN -2147483648

/*SORTING*/
void	ft_check_args(int argc, char **argv);
void	sort_stacks(t_node_list **stack_a, t_node_list **stack_b);
void	simple_sort(t_node_list **stack_a, t_node_list **stack_b);
int		ra(t_node_list **stack_a);
void	radix_sort(t_node_list **stack_a, t_node_list **stack_b);

/*SIMPLE SORTING*/
int		get_distance(t_node_list **stack, int index);
int		get_min(t_node_list **stack, int val);
void	sort_3(t_node_list **stack_a);
void	sort_4(t_node_list **stack_a, t_node_list **stack_b);
void	sort_5(t_node_list **stack_a, t_node_list **stack_b);

/*STACK OPERATIONS*/
int		push(t_node_list **stack_1, t_node_list **stack_2);
int		rotate(t_node_list **stack);
int		rev_rotate(t_node_list **stack);
int		swap(t_node_list	**stack);

/*INSTRUCTIONS*/
int		sa(t_node_list **stack_a);
int		sb(t_node_list **stack_b);
int		ss(t_node_list **stack_a, t_node_list **stack_b);
int		pa(t_node_list **stack_a, t_node_list **stack_b);
int		pb(t_node_list **stack_a, t_node_list **stack_b);

/*INSTRUCTIONS_SEC*/
int		rb(t_node_list **stack_b);
int		rr(t_node_list **stack_a, t_node_list **stack_b);
int		rra(t_node_list **stack_a);
int		rrb(t_node_list **stack_b);
int		rrr(t_node_list **stack_a, t_node_list **stack_b);

#endif
