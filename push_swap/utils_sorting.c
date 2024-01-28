/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-f <galves-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 21:47:09 by galves-f          #+#    #+#             */
/*   Updated: 2024/01/28 10:07:32 by galves-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_index_of_target(t_ds *t, int sender)
{
	int	target_idx;

	target_idx = -1;
	if (t->len == 0)
		target_idx = 0;
	else if (sender > t->max || sender < t->min)
		target_idx = find_index_of(t, t->min);
	else if (sender < peek(t, 0) && sender > peek(t, t->len - 1))
		target_idx = 0;
	else
		target_idx = find_index_of(t, smallest_with_limit(t, sender));
	return (target_idx);
}

int	find_index_of_target_reverse(t_ds *t, int sender)
{
	int	target_idx;

	target_idx = -1;
	if (t->len == 0)
		target_idx = 0;
	else if (sender > t->max || sender < t->min)
		target_idx = find_index_of(t, t->max);
	else if (sender > peek(t, 0) && sender < peek(t, t->len - 1))
		target_idx = 0;
	else
		target_idx = find_index_of(t, smallest_with_limit(t, sender)) + 1;
	return (target_idx);
}

int	price_of_element(t_ds *s, t_ds *t, int i_s, int (*find_i)(t_ds *t, int i))
{
	int	i_t;
	int	v_s;
	int	p_s;
	int	p_t;

	v_s = peek(s, i_s);
	i_t = find_i(t, v_s);
	if (i_s > s->len / 2)
		p_s = s->len - i_s;
	else
		p_s = i_s;
	if (i_t > s->len / 2)
		p_t = t->len - i_t;
	else
		p_t = i_t;
	if ((i_s > s->len / 2 && i_t > t->len / 2) || (i_s <= s->len / 2
			&& i_t <= t->len / 2))
	{
		if (p_s > p_t)
			return (p_s);
		else
			return (p_t);
	}
	else
		return (p_s + p_t);
}

int	find_cheapest(t_ds *s, t_ds *t, int (*find_idx)(t_ds *t, int i))
{
	int	i;
	int	cheapest_idx;
	int	cheapest_p;
	int	current_p;

	if (s->len == 1)
		return (0);
	i = 0;
	cheapest_idx = 0;
	cheapest_p = price_of_element(s, t, i, find_idx);
	while (i < s->len)
	{
		current_p = price_of_element(s, t, i, find_idx);
		if (current_p < cheapest_p)
		{
			cheapest_p = current_p;
			cheapest_idx = i;
		}
		i++;
	}
	return (cheapest_idx);
}

void	remaining_rotations_individual_stack(t_ds *a, int idx)
{
	while (idx != 0)
	{
		if (idx > a->len / 2)
		{
			rotate_reverse(a, 1);
			idx = (idx + 1) % a->len;
		}
		else
		{
			rotate(a, 1);
			idx--;
		}
	}
}
