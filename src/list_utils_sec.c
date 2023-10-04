/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_sec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverissi <gverissi@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:20:35 by gverissi          #+#    #+#             */
/*   Updated: 2023/10/04 18:45:18 by gverissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_free_stack(t_node_list **stack)
{
	t_node_list	*head;

	while (*stack)
	{
		head = (*stack)->next;
		free(*stack);
		*stack = head;
	}
}

void	make_index(t_node_list **node_list)
{
	t_node_list	*head;
	t_node_list	*current;
	t_node_list	*aux;
	int			index;

	head = *node_list;
	current = *node_list;
	aux = head;
	while (current)
	{
		index = 0;
		while (head)
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

void	ft_init_stack(t_node_list **stack, int argc, char **argv)
{
	t_node_list	*new;
	char		**args;
	int			i;

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
		new = ft_newlist(ft_atoi(args[i]));
		if (!new)
			ft_free_stack(&new);
		else
			ft_add_back(stack, new);
		i++;
	}
	make_index(stack);
	if (argc == 2)
		ft_free_list(args);
}
