/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_sec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverissi <gverissi@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:07:02 by gverissi          #+#    #+#             */
/*   Updated: 2023/09/21 17:38:16 by gverissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void    free_list(t_node_list **head)
{
    t_node_list *temp;

    while (*head)
    {
        temp = (*head)->next;
        free(*head);
        *head = temp;
    }
    exit(0);
}

void    ft_check_args(int argc, char **argv)
{
	int i;
	int	a;
	long	tmp;
	char	**args;

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
		tmp = ft_atoi(args[i]);
		if (!ft_isnum(args[i]))
			write(2, "Is not number", 13);
		if (!ft_contains(tmp, args, i))
			write(2, "Is not number", 13);
		if (tmp < INT_MIN || tmp > INT_MAX)
			write(2, "Is not number", 13);
		i++;
	}
	if (argc == 2)
		a = 2;
		while (a >= 0)
			free(args[i--]);
}