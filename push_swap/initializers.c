/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-f <galves-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:47:58 by galves-f          #+#    #+#             */
/*   Updated: 2024/01/24 21:28:46 by galves-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	number_of_arguments(char **numbers)
{
	int	count;

	count = 0;
	while (numbers[count])
		count++;
	return (count);
}

t_ds	*init_ds(char **numbers, int flag)
{
	t_ds	*s;
	int		size;
	long	num;

	(void)flag;
	if (numbers == NULL)
		return (NULL);
	size = number_of_arguments(numbers);
	s = malloc(sizeof(t_ds));
	if (s == NULL)
		return (NULL);
	s->len = 0;
	s->name = DS_A;
	s->arr = malloc(sizeof(int) * size);
	while (size != 0)
	{
		num = atoi_l(numbers[s->len++]);
		if (num > INT_MAX || num < INT_MIN)
			return (NULL);
		s->arr[--size] = (int)num;
	}
	return (s);
}

t_ds	*init_tmp_ds(size_t size)
{
	t_ds	*b;
	size_t	i;

	b = malloc(sizeof(t_ds));
	if (b == NULL)
		return (NULL);
	b->len = 0;
	b->name = DS_B;
	b->arr = malloc(sizeof(int) * size);
	i = 0;
	while (i < size)
		b->arr[i++] = 0;
	return (b);
}
