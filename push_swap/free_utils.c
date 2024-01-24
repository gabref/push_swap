/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-f <galves-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:32:46 by galves-f          #+#    #+#             */
/*   Updated: 2024/01/24 22:21:28 by galves-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_splitted_chars(char **splitted)
{
	int	i;

	i = 0;
	while (splitted[i] != NULL)
		free(splitted[i++]);
	free(splitted - 1);
}

void	free_ds(t_ds *s)
{
	if (s != NULL)
		free(s->arr);
	free(s);
}

void	free_all_ds(t_ds *a, t_ds *b, int ac_2, char **splitted)
{
	free_ds(a);
	free_ds(b);
	if (ac_2)
		free_splitted_chars(splitted);
}
