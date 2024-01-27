/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-f <galves-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:30:13 by galves-f          #+#    #+#             */
/*   Updated: 2024/01/27 14:57:40 by galves-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	putstr_fd(int fd, char *s)
{
	while (*s)
		(void)write(fd, s++, 1);
}

void	putstr(char *s)
{
	while (*s)
		(void)write(1, s++, 1);
}

void	print_operation(char *op, char *ds_name)
{
	putstr(op);
	putstr(ds_name);
	putstr("\n");
}

void	print_array(t_ds *s)
{
	int	i;

	i = s->len;
	printf("%s | ", s->name);
	while (i)
		printf("%d ", s->arr[--i]);
	if (s->len > 0)
		printf("| max: %d, min: %d", s->max, s->min);
	printf("\n");
}
