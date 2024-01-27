/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-f <galves-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:40:27 by galves-f          #+#    #+#             */
/*   Updated: 2024/01/27 21:36:07 by galves-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	biggest_from_index(t_ds *s, int idx)
{
	int	max;
	int	n;

	if (idx > s->len - 1)
		return (0);
	max = peek(s, idx);
	while (idx < s->len)
	{
		n = peek(s, idx++);
		if (n > max)
			max = n;
	}
	return (max);
}

int	smallest_from_index(t_ds *s, int idx)
{
	int	min;
	int	n;

	if (idx > s->len - 1)
		return (0);
	min = peek(s, idx);
	while (idx < s->len)
	{
		n = peek(s, idx++);
		if (n < min)
			min = n;
	}
	return (min);
}

void	push(t_ds *dst, t_ds *src)
{
	if (src->len == 0)
		return ;
	else if (src->len == 1)
	{
		src->max = 0;
		src->min = 0;
	}
	else if (peek(src, 0) == src->max)
		src->max = biggest_from_index(src, 1);
	else if (peek(src, 0) == src->min)
		src->min = smallest_from_index(src, 1);
	if (dst->len == 0)
	{
		dst->max = peek(src, 0);
		dst->min = peek(src, 0);
	}
	else if (peek(src, 0) > dst->max)
		dst->max = peek(src, 0);
	else if (peek(src, 0) < dst->min)
		dst->min = peek(src, 0);
	dst->arr[dst->len++] = src->arr[--(src->len)];
	print_operation(OPERATION_PUSH, dst->name);
}
