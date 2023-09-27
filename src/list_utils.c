/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverissi <gverissi@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:20:24 by gverissi          #+#    #+#             */
/*   Updated: 2023/09/27 13:33:05 by gverissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_node_list	*ft_newlist(int value_to_add)
{
	t_node_list	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->value = value_to_add;
	new->next = NULL;
	return (new);
}

void	ft_add_front(t_node_list **stack, t_node_list *new)
{
	if (!new || !stack)
		return ;
	new->next = *stack;
	*stack = new;
}

void	ft_add_back(t_node_list **stack, t_node_list *new)
{
	t_node_list	*tmp_lst;

	tmp_lst = *stack;
	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	while (tmp_lst->next != NULL)
	{
		tmp_lst = tmp_lst->next;
	}
	tmp_lst->next = new;
}

int	list_size(t_node_list *head)
{
	if (head == NULL)
		return (0);
	else
		return (1 + list_size(head->next));
}
