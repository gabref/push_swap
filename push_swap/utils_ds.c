/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-f <galves-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 11:08:19 by galves-f          #+#    #+#             */
/*   Updated: 2024/01/27 15:21:50 by galves-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	not_sorted(t_ds *a)
{
	int	i;

	i = (int)a->len - 1;
	while (--i >= 0)
		if (a->arr[i] < a->arr[i + 1])
			return (1);
	return (0);
}

int	peek(t_ds *s, int top_index)
{
	return (s->arr[s->len - 1 - top_index]);
}

int	find_index_of_target(t_ds *t, int sender)
{
	int	target_idx;

	target_idx = -1;
	if (sender > t->max || sender < t->min)
		target_idx = find_index_of(t, t->min);
	else if (sender < peek(t, 0) && sender > peek(t, t->len - 1))
		target_idx = 0;
	else
		target_idx = find_index_of(t, smallest_with_limit(t, sender));
	return (target_idx);
}

int	price_of_element(t_ds *s, t_ds *t, int i_s)
{
	int	i_t;
	int					v_s;
	int					p_s;
	int					p_t;

	v_s = peek(s, i_s);
	i_t = find_index_of_target(t, v_s);
	p_s = i_s > s->len / 2 ? s->len - i_s : i_s;
	p_t = i_t > t->len / 2 ? t->len - i_t : i_t;
	if ((i_s > s->len / 2 && i_t > t->len / 2) || (i_s <= s->len / 2
			&& i_t <= t->len / 2))
		if (p_s > p_t)
			return (p_s);
		else
			return (p_t);
	else
		return (p_s + p_t);
}

int	find_cheapest(t_ds *s, t_ds *t)
{
	int	i;
	int	cheapest_idx;
	int					cheapest_p;
	int					current_p;

	if (s->len == 1)
		return (0);
	i = 0;
	cheapest_idx = 0;
	cheapest_p = price_of_element(s, t, i);
	while (i < s->len)
	{
		current_p = price_of_element(s, t, i);
		if (current_p < cheapest_p)
		{
			cheapest_p = current_p;
			cheapest_idx = i;
		}
		i++;
	}
	return (cheapest_idx);
}

void	move_cheapest(t_ds *s, t_ds *t, int cheapest_idx)
{
	int	target_idx;

	int c_v = peek(s, cheapest_idx);
	target_idx = find_index_of_target(t, c_v);
	if ((cheapest_idx > s->len / 2 && target_idx > t->len / 2)
		|| (cheapest_idx <= s->len / 2 && target_idx <= t->len / 2))
		while (target_idx != 0 && cheapest_idx != 0)
		{
			if (cheapest_idx > s->len / 2 && target_idx > t->len / 2)
			{
				rotate_reverse_both(s, t);
				cheapest_idx = (cheapest_idx + 1) % s->len;
				target_idx = (target_idx + 1) % t->len;
			}
			else
			{
				rotate_both(s, t);
				cheapest_idx--;
				target_idx--;
			}
		}
	while (cheapest_idx != 0)
		if (cheapest_idx > s->len / 2)
		{
			rotate_reverse(s, 1);
			cheapest_idx = (cheapest_idx + 1) % s->len;
		}
		else
		{
			rotate(s, 1);
			cheapest_idx--;
		}
	while (target_idx != 0)
		if (target_idx > t->len / 2)
		{
			rotate_reverse(t, 1);
			target_idx = (target_idx + 1) % t->len;
		}
		else
		{
			rotate(t, 1);
			target_idx--;
		}
	push(t, s);
}
