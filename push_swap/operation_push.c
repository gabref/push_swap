/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-f <galves-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:40:27 by galves-f          #+#    #+#             */
/*   Updated: 2024/01/24 17:58:36 by galves-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push(t_ds *dst, t_ds *src)
{
	if (src->len == 0)
		return ;
	dst->arr[dst->len++] = src->arr[--(src->len)];
	print_operation(OPERATION_PUSH, dst->name);
}
