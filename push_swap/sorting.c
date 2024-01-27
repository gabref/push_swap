/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-f <galves-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:58:18 by galves-f          #+#    #+#             */
/*   Updated: 2024/01/27 11:14:04 by galves-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_ds *a, t_ds *b)
{
	int					top;
	long unsigned int	i;
	int					direction;

	while (not_sorted(a))
	{
		while (a->len > 2)
			push(b, a);
		if (peek(a, 0) > peek(a, 1))
			swap(a, 1);
		while (b->len > 0)
		{
			top = smallest_with_limit(a, peek(b, 0));
			i = 0;
			direction = 1;
			while (peek(a, i) != top)
				i++;
			if (i > a->len / 2)
				direction = 0;
			while (peek(a, 0) != top)
				if (direction)
					rotate(a, 1);
				else
					rotate_reverse(a, 1);
			push(a, b);
		}
		while (not_sorted(a))
			rotate(a, 1);
	}
}
