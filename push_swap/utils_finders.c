/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_finders.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-f <galves-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 11:05:05 by galves-f          #+#    #+#             */
/*   Updated: 2024/01/27 11:12:55 by galves-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_duplicate(t_ds *s, int n)
{
	long unsigned int	i;

	i = 0;
	if (!s)
		return (0);
	while (i < s->len)
		if (s->arr[s->cap - 1 - i++] == n)
			return (1);
	return (0);
}

int	find_index_of(t_ds *s, int n)
{
	long unsigned int	i;

	i = 0;
	if (!s)
		return (0);
	while (i < s->len)
		if (s->arr[s->cap - 1 - i++] == n)
			return (i);
	return (-1);
}

int	smallest(t_ds *s)
{
	long unsigned int	i;
	int					min;
	int					n;

	i = 0;
	min = peek(s, 0);
	while (i < s->len)
	{
		n = peek(s, i++);
		if (n < min)
			min = n;
	}
	return (min);
}

int	biggest(t_ds *s)
{
	long unsigned int	i;
	int					max;
	int					n;

	i = 0;
	max = peek(s, 0);
	while (i < s->len)
	{
		n = peek(s, i++);
		if (n > max)
			max = n;
	}
	return (max);
}

int	smallest_with_limit(t_ds *s, int limit)
{
	long unsigned int	i;
	int					min;
	int					n;
	int					max;
	int					flag;

	i = 0;
	flag = 0;
	min = smallest(s);
	max = biggest(s);
	if (max < limit)
		max = limit;
	while (i < s->len)
	{
		n = peek(s, i++);
		if (n > limit && n <= max)
		{
			flag = 1;
			max = n;
		}
	}
	if (flag)
		return (max);
	return (min);
}
