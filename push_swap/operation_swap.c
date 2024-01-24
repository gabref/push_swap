/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-f <galves-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:17:11 by galves-f          #+#    #+#             */
/*   Updated: 2024/01/24 22:21:39 by galves-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_ds *s, int flag)
{
	int	t;

	if (s->len < 2)
		return ;
	t = s->arr[s->len - 1];
	s->arr[s->len - 1] = s->arr[s->len - 2];
	s->arr[s->len - 2] = t;
	if (flag)
		print_operation(OPERATION_SWAP, s->name);
}

void	swap_both(t_ds *a, t_ds *b)
{
	swap(a, 0);
	swap(b, 0);
	print_operation(OPERATION_SWAP, DS_BOTH_SWAP);
}
