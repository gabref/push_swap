/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-f <galves-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:58:18 by galves-f          #+#    #+#             */
/*   Updated: 2024/01/24 19:53:16 by galves-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	not_sorted(t_ds *a)
{
	int	i;
	int					swaps_needed;

	i = (int) a->len - 1;
	swaps_needed = 0;
	while (--i >= 0)
		if (a->arr[i] < a->arr[i + 1])
			swaps_needed++;
	return (swaps_needed);
}

void	sort(t_ds *a, t_ds *b)
{
	(void)b;
	while (not_sorted(a))
	{
		if (a->arr[a->len - 1] > a->arr[a->len - 2])
			swap(a, 1);
		else
			rotate(a, 1);
	}
}
