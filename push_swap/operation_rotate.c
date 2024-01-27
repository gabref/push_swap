/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-f <galves-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:00:57 by galves-f          #+#    #+#             */
/*   Updated: 2024/01/27 14:57:29 by galves-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_ds *s, int flag)
{
	int	i;
	int	tmp;

	if (s->len < 2)
		return ;
	i = s->len - 1;
	tmp = s->arr[i++];
	while (--i > 0)
		s->arr[i] = s->arr[i - 1];
	s->arr[i] = tmp;
	if (flag)
		print_operation(OPERATION_ROTATE, s->name);
}

void	rotate_reverse(t_ds *s, int flag)
{
	int	i;
	int					tmp;

	if (s->len < 2)
		return ;
	i = 0;
	tmp = s->arr[i];
	while (++i < s->len)
		s->arr[i - 1] = s->arr[i];
	s->arr[--i] = tmp;
	if (flag)
		print_operation(OPERATION_ROTATE_REVERSE, s->name);
}

void	rotate_both(t_ds *a, t_ds *b)
{
	rotate(a, 0);
	rotate(b, 0);
	print_operation(OPERATION_ROTATE, DS_BOTH_ROTATE);
}

void	rotate_reverse_both(t_ds *a, t_ds *b)
{
	rotate_reverse(a, 0);
	rotate_reverse(b, 0);
	print_operation(OPERATION_ROTATE_REVERSE, DS_BOTH_ROTATE);
}
