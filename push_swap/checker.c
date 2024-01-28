/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-f <galves-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 05:19:49 by galves-f          #+#    #+#             */
/*   Updated: 2024/01/28 06:18:58 by galves-f         ###   ########.fr       */
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
	if (a == NULL || b == NULL || !process_operations(a, b))
	{
		free_all_ds(a, b, ac == 2, av + 1);
		putstr_fd(2, "Error\n");
		return (1);
	}
	if (check_ds(a, b))
		putstr_fd(2, "OK\n");
	else
		putstr_fd(2, "KO\n");
	free_all_ds(a, b, ac == 2, av + 1);
	return (0);
}
