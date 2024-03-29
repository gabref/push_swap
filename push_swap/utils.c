/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-f <galves-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 20:56:06 by galves-f          #+#    #+#             */
/*   Updated: 2024/01/27 11:15:04 by galves-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_space(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

long	atoi_l(char *s)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	while (*s && is_space(*s))
		s++;
	if (*s == '+')
		s++;
	else if (*s == '-')
	{
		sign *= -1;
		s++;
	}
	while (*s && *s >= '0' && *s <= '9')
		res = (res * 10) + (*s++ - 0x30);
	return (res * sign);
}

int	not_a_number(char *str)
{
	if (!(*str == '+' || *str == '-' || (*str >= '0' && *str <= '9')))
		return (1);
	if ((*str == '+' || *str == '-') && !(str[1] >= '1' && str[1] <= '9'))
		return (1);
	while (*str++)
		if (*str && !(*str >= '0' && *str <= '9'))
			return (1);
	return (0);
}
