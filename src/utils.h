/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverissi <gverissi@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:30:10 by gverissi          #+#    #+#             */
/*   Updated: 2023/09/27 15:34:28 by gverissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# include "../libft/libft.h"

/*DEFINING LIST*/
typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
}				t_node_list;

/*UTIL_FUNCS*/
int			ft_isnum(char *num);
int			ft_contains(int num, char **argv, int i);
void		ft_error(char *msg);
void		ft_free_list(char **str);
int			is_sorted(t_node_list **stack);

/*LIST_UTILS*/
t_node_list	*ft_newlist(int value_to_add);
void		ft_add_front(t_node_list **stack, t_node_list *new);
void		ft_add_back(t_node_list **stack, t_node_list *new);
int			list_size(t_node_list *head);

/*LIST_UTILS_SEC*/
void		make_index(t_node_list **node_list);
void		ft_free_stack(t_node_list **stack);
void		ft_init_stack(t_node_list **stack, int argc, char **argv);

#endif
