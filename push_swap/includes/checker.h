/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 15:54:34 by ccartman          #+#    #+#             */
/*   Updated: 2021/08/18 16:47:24 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# define BUFFER_SIZE 1024
# define MAX_INT_STR "2147483647"
# define MAX_INT_STRLEN 10
# define MIN_INT_STR "2147483648"
# define MIN_INT_STRLEN 10
# define ERRMES "Error\n"
# define ERRMESLEN 6
# define STACK_A 'a'
# define STACK_B 'b'
# define STACKS_AB 'c'
# define SWAP_A "sa"
# define SWAP_B "sb"
# define SWAP_AB "ss"
# define PUSH_A "pa"
# define PUSH_B "pb"
# define ROTATE_A "ra"
# define ROTATE_B "rb"
# define ROTATE_AB "rr"
# define REV_ROTATE_A "rra"
# define REV_ROTATE_B "rrb"
# define REV_ROTATE_AB "rrr"
# include "libft.h"

typedef struct s_list
{
	int				data;
	struct s_list	*next;
}	t_list;

typedef struct s_stacks
{
	t_list	*a_top;
	t_list	*a_end;
	t_list	*b_top;
	t_list	*b_end;
}				t_stacks;

int		check_args(char **args);

void	instructions_read(t_stacks *stacks);

int		get_next_line(int fd, char **line);

t_list	*ft_list_last(t_list *list);

void	ft_list_push_front(t_list **list, int num);

void	ft_list_push_back(t_list **begin, int num);

void	ft_list_clear(t_list *a);

int		ft_list_issorted(t_list *list);

size_t	ft_list_size(t_list *list);

void	ft_list_remove(t_list **list, size_t n);

void	stack_swap(t_stacks *stacks, int sign);

void	stack_push(t_stacks *stacks, int sign);

void	stack_rotate(t_stacks *stacks, int sign);

void	stack_rev_rotate(t_stacks *stacks, int sign);

void	ft_strjoin_and_free_src(char **src, const char *part);

#endif
