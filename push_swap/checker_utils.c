/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-f <galves-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 05:25:47 by galves-f          #+#    #+#             */
/*   Updated: 2024/01/28 10:27:48 by galves-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	my_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int	execute_operation(t_ds *a, t_ds *b, char *op)
{
	if (my_strcmp(op, "sa\n") == 0)
		swap(a, 0);
	else if (my_strcmp(op, "sb\n") == 0)
		swap(b, 0);
	else if (my_strcmp(op, "ss\n") == 0)
		swap_both(a, b, 0);
	else if (my_strcmp(op, "ra\n") == 0)
		rotate(a, 0);
	else if (my_strcmp(op, "rb\n") == 0)
		rotate(b, 0);
	else if (my_strcmp(op, "rr\n") == 0)
		rotate_both(a, b, 0);
	else if (my_strcmp(op, "rra\n") == 0)
		rotate_reverse(a, 0);
	else if (my_strcmp(op, "rrb\n") == 0)
		rotate_reverse(b, 0);
	else if (my_strcmp(op, "rrr\n") == 0)
		rotate_reverse_both(a, b, 0);
	else if (my_strcmp(op, "pa\n") == 0)
		push(a, b, 0);
	else if (my_strcmp(op, "pb\n") == 0)
		push(b, a, 0);
	else
		return (0);
	return (1);
}

int	process_operations(t_ds *a, t_ds *b)
{
	char	*operation;
	int		op_ok;

	operation = get_next_line(STDIN_FILENO);
	op_ok = 1;
	while (operation && op_ok == 1)
	{
		if (!execute_operation(a, b, operation))
			op_ok = 0;
		free(operation);
		operation = get_next_line(STDIN_FILENO);
	}
	return (op_ok);
}

int	check_ds(t_ds *a, t_ds *b)
{
	if (b->len != 0)
		return (0);
	if (not_sorted(a))
		return (0);
	return (1);
}
