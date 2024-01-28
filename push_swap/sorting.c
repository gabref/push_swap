/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-f <galves-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:58:18 by galves-f          #+#    #+#             */
/*   Updated: 2024/01/28 09:34:50 by galves-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3_elements(t_ds *s)
{
	int	max;

	max = biggest(s);
	if (peek(s, 0) == max)
		rotate(s, 1);
	else if (peek(s, 1) == max)
		rotate_reverse(s, 1);
	if (peek(s, 0) > peek(s, 1))
		swap(s, 1);
}

void	sort(t_ds *a, t_ds *b)
{
	int	i;
	int	direction;

	while (a->len > 3)
		move_cheapest_reverse(a, b, find_cheapest_reverse(a, b));
	sort_3_elements(a);
	while (b->len > 0)
		move_cheapest(b, a, 0);
	i = find_index_of(a, a->min);
	direction = i <= a->len / 2;
	while (i != 0)
	{
		if (direction)
		{
			rotate(a, 1);
			i--;
		}
		else
		{
			rotate_reverse(a, 1);
			i = (i + 1) % a->len;
		}
	}
}

// void	sort(t_ds *a, t_ds *b)
// {
// 	int	i;
// 	int	direction;
//
// 	while (a->len > 3)
// 		push(b, a);
// 	sort_3_elements(a);
// 	while (b->len > 0)
// 		move_cheapest(b, a, find_cheapest(b, a));
// 	i = find_index_of(a, a->min);
// 	direction = i <= a->len / 2;
// 	while (i != 0)
// 	{
// 		if (direction)
// 		{
// 			rotate(a, 1);
// 			i--;
// 		}
// 		else
// 		{
// 			rotate_reverse(a, 1);
// 			i = (i + 1) % a->len;
// 		}
// 	}
// }

/*
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
*/
