/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 15:53:54 by ccartman          #+#    #+#             */
/*   Updated: 2021/08/18 16:47:35 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# define MAX_INT_STR "2147483647"
# define MAX_INT_STRLEN 10
# define MIN_INT_STR "2147483648"
# define MIN_INT_STRLEN 10
# define ERRMES "Error\n"
# define ERRMESLEN 6
# define STACK_A 'a'
# define STACK_B 'b'
# define STACKS_AB 'c'
# define SWAP_A "sa\n"
# define SWAP_B "sb\n"
# define SWAP_AB "ss\n"
# define PUSH_A "pa\n"
# define PUSH_B "pb\n"
# define ROTATE_A "ra\n"
# define ROTATE_B "rb\n"
# define ROTATE_AB "rr\n"
# define REV_ROTATE_A "rra\n"
# define REV_ROTATE_B "rrb\n"
# define REV_ROTATE_AB "rrr\n"
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
	t_list	*frame;
	char	*instructions;
}				t_stacks;

int		check_args(char **args);

void	heap_sort(int *array, size_t size);

t_list	*ft_list_last(t_list *list);

void	ft_list_push_front(t_list **list, int num);

void	ft_list_push_back(t_list **begin, int num);

void	ft_list_clear(t_list *a);

int		ft_list_issorted(t_list *list);

size_t	ft_list_size(t_list *list);

void	ft_list_remove(t_list **list, size_t n);

int		list_middle_data(t_list *list, size_t size);

size_t	list_count_lessmid(t_list *list, size_t size, int mid);

void	stack_swap(t_stacks *stacks, int sign);

void	stack_push(t_stacks *stacks, int sign);

void	stack_rotate(t_stacks *stacks, int sign);

void	stack_rev_rotate(t_stacks *stacks, int sign);

void	stack_sort(t_stacks *stacks);

void	stack_2elem_sort(t_stacks *stacks, int sign);

void	stack_a3only_sort(t_stacks *stacks);

void	stack_a3_sort(t_stacks *stacks);

void	stack_b3_sort(t_stacks *stacks);

void	frame_split(t_stacks *stacks);

void	ft_strjoin_and_free_src(char **src, const char *part);

#endif
