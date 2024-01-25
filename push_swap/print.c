/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-f <galves-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:30:13 by galves-f          #+#    #+#             */
/*   Updated: 2024/01/25 14:11:47 by galves-f         ###   ########.fr       */
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
	long unsigned int	i;

	i = s->len;
	while (i)
		printf("%d ", s->arr[--i]);
	printf("\n");
}
