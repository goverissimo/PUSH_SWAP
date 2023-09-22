/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverissi <gverissi@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:50:55 by gverissi          #+#    #+#             */
/*   Updated: 2023/09/21 20:34:17 by gverissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node_list	*a;
	t_node_list	*b;
	int		i;

	check_arguments(argc, argv);
	i = 1;
	a = NULL;
	b = NULL;
	while (i < argc)
		atoi_list(argv[i++], &a);
	check_list(&a);
	start_sorting(&a, &b);
	free_list(&a);
}
