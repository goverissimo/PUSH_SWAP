/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverissi <gverissi@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 22:38:26 by gverissi          #+#    #+#             */
/*   Updated: 2023/07/12 22:38:45 by gverissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
Node	*rrr(Node **stack_a, Node **stack_b)
{
	*stack_a = rra(*stack_a);
	*stack_b = rrb(*stack_b);
}
