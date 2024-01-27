/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-f <galves-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:40:27 by galves-f          #+#    #+#             */
/*   Updated: 2024/01/27 11:38:12 by galves-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	biggest_from_index(t_ds *s, int idx)
{
	long unsigned int	i;
	int					max;
	int					n;

	i = (long unsigned int)idx;
	max = peek(s, i);
	while (i < s->len)
	{
		n = peek(s, i++);
		if (n > max)
			max = n;
	}
	return (max);
}

int	smallest_from_index(t_ds *s, int idx)
{
	long unsigned int	i;
	int					min;
	int					n;

	i = (long unsigned int)idx;
	min = peek(s, i);
	while (i < s->len)
	{
		n = peek(s, i++);
		if (n < min)
			min = n;
	}
	return (min);
}

void	push(t_ds *dst, t_ds *src)
{
	if (src->len == 0)
		return ;
	if (peek(src, 0) == src->max)
		src->max = biggest_from_index(src, 1);
	else if (peek(src, 0) == src->min)
		src->max = smallest_from_index(src, 1);
	if (peek(src, 0) > dst->max)
		dst->max = peek(src, 0);
	else if (peek(src, 0) < dst->min)
		dst->min = peek(src, 0);
	dst->arr[dst->len++] = src->arr[--(src->len)];
	print_operation(OPERATION_PUSH, dst->name);
}
