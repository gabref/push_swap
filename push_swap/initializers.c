/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-f <galves-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:47:58 by galves-f          #+#    #+#             */
/*   Updated: 2024/01/25 13:21:44 by galves-f         ###   ########.fr       */
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

t_ds	*alloc_ds(char *name, int size)
{
	t_ds	*s;
	int		i;

	s = malloc(sizeof(t_ds));
	if (s == NULL)
		return (NULL);
	s->len = 0;
	s->cap = size;
	s->name = name;
	s->arr = malloc(sizeof(int) * size);
	if (s->arr == NULL)
		return (NULL);
	i = 0;
	while (i < size)
		s->arr[i++] = 0;
	return (s);
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
	s = alloc_ds(DS_A, size);
	if (!s)
		return (NULL);
	while (size != 0)
	{
		num = atoi_l(numbers[s->len]);
		if (num > INT_MAX || num < INT_MIN || not_a_number(numbers[s->len])
			|| find_duplicate(s, num))
			return (NULL);
		s->arr[--size] = (int)num;
		s->len++;
	}
	return (s);
}

t_ds	*init_tmp_ds(char **numbers)
{
	t_ds	*b;
	int		size;

	size = number_of_arguments(numbers);
	b = alloc_ds(DS_B, size);
	return (b);
}
