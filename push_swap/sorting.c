/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-f <galves-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:58:18 by galves-f          #+#    #+#             */
/*   Updated: 2024/01/28 10:29:06 by galves-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_cheapest(t_ds *s, t_ds *t, int cheapest_idx,
		int (*find_idx)(t_ds *t, int i))
{
	int	target_idx;

	target_idx = find_idx(t, peek(s, cheapest_idx));
	if ((cheapest_idx > s->len / 2 && target_idx > t->len / 2)
		|| (cheapest_idx <= s->len / 2 && target_idx <= t->len / 2))
	{
		while (target_idx != 0 && cheapest_idx != 0)
		{
			if (cheapest_idx > s->len / 2 && target_idx > t->len / 2)
			{
				rotate_reverse_both(s, t, 1);
				cheapest_idx = (cheapest_idx + 1) % s->len;
				target_idx = (target_idx + 1) % t->len;
			}
			else
			{
				rotate_both(s, t, 1);
				cheapest_idx--;
				target_idx--;
			}
		}
	}
	remaining_rotations_individual_stack(s, cheapest_idx);
	remaining_rotations_individual_stack(t, target_idx);
	push(t, s, 1);
}

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
		move_cheapest(a, b, find_cheapest(a, b, &find_index_of_target_reverse),
			&find_index_of_target_reverse);
	sort_3_elements(a);
	while (b->len > 0)
		move_cheapest(b, a, 0, &find_index_of_target);
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

/*
void	sort(t_ds *a, t_ds *b)
{
	int	i;
	int	direction;

	while (a->len > 3)
		push(b, a);
	sort_3_elements(a);
	while (b->len > 0)
		move_cheapest(b, a, find_cheapest(b, a));
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
*/

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
