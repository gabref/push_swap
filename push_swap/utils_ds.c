/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-f <galves-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 11:08:19 by galves-f          #+#    #+#             */
/*   Updated: 2024/01/27 11:17:55 by galves-f         ###   ########.fr       */
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
