/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverissi <gverissi@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:20:33 by gverissi          #+#    #+#             */
/*   Updated: 2023/09/21 16:54:53 by gverissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../push_swap.h"

void	radix_sort(t_node_list **stack_a, t_node_list **stack_b)
{
	t_node_list	*head_a;
	int		i;
	int		j;
	int		size;
	int		max_bits;

	i = 0;
	head_a = *stack_a;
	size = ft_lstsize(head_a); //numero de vezes que vai ser iterado
	max_bits = 0;
	while (((size-1) >> max_bits++) != 0)
		++max_bits;
	while (i < max_bits) //enquanto não percorrer o numero maximo de bits
	{
		j = 0;
		while (j++ < size) //percorrer cada elemento da lista
		{
			head_a = *stack_a; //head_a é inicializado de novo para a head do stack A
			if (((head_a->index >> i) & 1) == 1) //SE o Bit i estiver set (=1), 
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		while (ft_lstsize(*stack_b) != 0)
			pa(stack_a, stack_b);
		i++;
	}
}




