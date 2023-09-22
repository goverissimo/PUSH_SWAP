/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverissi <gverissi@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:20:29 by gverissi          #+#    #+#             */
/*   Updated: 2023/09/21 21:33:06 by gverissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef push_swap
# define push_swap
# include "list/list.h"

/*UTILS.C*/
int	ft_strlen(const char *str);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_printerr(char *msg, t_node_list **head);



/*SORTING*/

/*SORTING.C*/
void	radix_sort(t_node_list **stack_a, t_node_list **stack_b);
/*INDEX.C*/
void make_index(t_node_list **node_list);
void sort_stacks(t_node_list **stack_a, t_node_list **stack_b);


#endif