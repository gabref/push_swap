/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-f <galves-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:08:29 by galves-f          #+#    #+#             */
/*   Updated: 2024/01/28 07:27:15 by galves-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define DS_A "a"
# define DS_B "b"
# define DS_BOTH_SWAP "s"
# define DS_BOTH_ROTATE "r"
# define OPERATION_SWAP "s"
# define OPERATION_PUSH "p"
# define OPERATION_ROTATE "r"
# define OPERATION_ROTATE_REVERSE "rr"
# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_ds
{
	int		len;
	int		cap;
	int		min;
	int		max;
	int		*arr;
	char	*name;
}			t_ds;

void		print_array(t_ds *s);
t_ds		*init_ds(char **numbers);
t_ds		*init_tmp_ds(char **numbers);

void		swap(t_ds *s, int flag);
void		swap_both(t_ds *a, t_ds *b);
void		push(t_ds *dst, t_ds *src);
void		rotate(t_ds *s, int flag);
void		rotate_reverse(t_ds *s, int flag);
void		rotate_both(t_ds *a, t_ds *b);
void		rotate_reverse_both(t_ds *a, t_ds *b);

void		free_splitted_chars(char **splitted);
void		free_ds(t_ds *s);
void		free_all_ds(t_ds *a, t_ds *b, int ac_2, char **splitted);

void		sort(t_ds *a, t_ds *b);
int			not_sorted(t_ds *a);

void		putstr_fd(int fd, char *s);
void		putstr(char *s);
char		**split(char *str, char sep);
long		atoi_l(char *s);
int			find_duplicate(t_ds *s, int n);
int			not_a_number(char *str);
int			peek(t_ds *s, int top_index);
int			smallest(t_ds *s);
int			biggest(t_ds *s);
int			smallest_with_limit(t_ds *s, int limit);
void		exit_with_error(void);
int			find_index_of(t_ds *s, int n);
void		move_cheapest(t_ds *s, t_ds *t, int cheapest_idx);
void		move_cheapest_reverse(t_ds *s, t_ds *t, int cheapest_idx);
int			find_cheapest(t_ds *s, t_ds *t);
int			find_cheapest_reverse(t_ds *s, t_ds *t);

void		print_operation(char *op, char *ds_name);

char		*get_next_line(int fd);
int			has_newline(int start, char *str);
int			find_newline(char *str);
int			ft_strlen(char *str);
char		*strjoin(char *s1, char *s2, int s1_len, int s2_len);

int			process_operations(t_ds *a, t_ds *b);
int			check_ds(t_ds *a, t_ds *b);

#endif
