/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-f <galves-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:51:28 by galves-f          #+#    #+#             */
/*   Updated: 2024/01/27 15:22:16 by galves-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_ds	*a;
	t_ds	*b;

	if (ac == 1 || (ac == 2 && !av[1][0]))
		exit_with_error();
	else if (ac == 2)
		av = split(av[1], ' ');
	a = init_ds(&av[1]);
	b = init_tmp_ds(&av[1]);
	if (a == NULL || b == NULL)
	{
		free_all_ds(a, b, ac == 2, av + 1);
		putstr_fd(2, "Error\n");
		return (1);
	}
	// print_array(a);
	// print_array(b);
	if (not_sorted(a))
	{
		// printf("sorting\n");
		sort(a, b);
	}
	// print_array(a);
	// print_array(b);
	free_all_ds(a, b, ac == 2, av + 1);
	return (0);
}
