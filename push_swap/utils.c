/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-f <galves-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 20:56:06 by galves-f          #+#    #+#             */
/*   Updated: 2024/01/25 13:23:09 by galves-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_space(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

long	atoi_l(char *s)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	while (*s && is_space(*s))
		s++;
	if (*s == '+')
		s++;
	else if (*s == '-')
	{
		sign *= -1;
		s++;
	}
	while (*s && *s >= '0' && *s <= '9')
		res = (res * 10) + (*s++ - 0x30);
	return (res * sign);
}

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

int	not_a_number(char *str)
{
	if (!(*str == '+' || *str == '-' || (*str >= '0' && *str <= '9')))
		return (1);
	if ((*str == '+' || *str == '-') && !(str[1] >= '1' && str[1] <= '9'))
		return (1);
	while (*str++)
		if (*str && !(*str >= '0' && *str <= '9'))
			return (1);
	return (0);
}

int	peek(t_ds *s, int top_index)
{
	return (s->arr[s->len - 1 - top_index]);
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
