/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-f <galves-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:51:28 by galves-f          #+#    #+#             */
/*   Updated: 2024/01/24 21:40:22 by galves-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_ds	*a;
	t_ds	*b;

	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	else if (ac == 2)
		av = split(av[1], ' ');
	a = init_ds(&av[1], ac == 2);
	b = init_tmp_ds(&av[1]);
	if (a == NULL || b == NULL)
	{
		free_all_ds(a, b, ac == 2, av + 1);
		putstr("Error\n");
		return (1);
	}
	if (not_sorted(a))
	{
		printf("sorting\n");
		sort(a, b);
	}
	print_array(a);
	free_all_ds(a, b, ac == 2, av + 1);
	return (0);
}
