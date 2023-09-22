/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverissi <gverissi@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:20:24 by gverissi          #+#    #+#             */
/*   Updated: 2023/09/21 17:19:17 by gverissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
/*Creates a new list, allocate it in memory and inicialize values and index*/
t_node_list *ft_newlist(int value_to_add)
{
	t_node_list *new;
	new = malloc(sizeof(*new));
	if (!new)
		return NULL;
	new->value = value_to_add;
	new->next = NULL;
	return(new);
}

t_node_list *ft_add_front(t_node_list **stack, t_node_list *new)
{
	if (!stack || !new)
		return;
	new->next = *stack;
	*stack = new;
}

t_node_list *ft_getlast(t_node_list *stack)
{
	t_node_list *temp;

	temp = stack;
	while (temp->next != NULL)
	{
		temp = temp->next;
		if(temp->next == NULL)
			return temp;
	}
	return(temp);
}

t_node_list *ft_add_back(t_node_list **stack, t_node_list *value)
{

    t_node_list *new;
	if (!value)
		return;
    if (*stack)
    {
        new = ft_getlast(*stack);
        new->next = value;
        value->next = NULL;
    }
    else
    {
        *stack = value;
        (*stack)->next = NULL;
    }
}

int list_size(t_node_list *head)
{
    if (head == NULL)
		return 0;
    else
		return (1 + recursive_length(head->next));
}