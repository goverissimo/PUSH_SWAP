/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverissi <gverissi@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 20:06:02 by gverissi          #+#    #+#             */
/*   Updated: 2023/09/21 17:31:35 by gverissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/*Defining INT MAX & MIN*/
# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
}				t_node_list;

/*LIST UTILS*/
t_node_list *ft_newlist(int value_to_add);
t_node_list *ft_add_front(t_node_list **stack, t_node_list *new);
t_node_list *ft_getlast(t_node_list *stack);
t_node_list *ft_add_back(t_node_list **stack, t_node_list *value);
int list_size(t_node_list *head);
void    free_list(t_node_list **head);
