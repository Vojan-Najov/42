/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 13:17:46 by ccartman          #+#    #+#             */
/*   Updated: 2021/08/17 13:18:00 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	frame_split_cycle(t_stacks *stacks, int *count_a, int *count_b);

static void	stack_a_frame_split(t_stacks *stacks, int count);

static void	stack_a_frame_split_cycle(t_stacks *stacks, int count, \
										int *count_a, int *count_b);

void	frame_split(t_stacks *stacks)
{
	int	count_a;
	int	count_b;

	count_a = 0;
	count_b = 0;
	frame_split_cycle(stacks, &count_a, &count_b);
	stacks->frame->data += count_b;
	if (stacks->frame->next)
		while (count_b-- > 0)
			stack_rev_rotate(stacks, STACK_B);
	if (count_a == 1)
		return ;
	if (count_a == 2)
		stack_2elem_sort(stacks, STACK_A);
	else if (count_a == 3)
		stack_a3_sort(stacks);
	else
		stack_a_frame_split(stacks, count_a);
}

static void	frame_split_cycle(t_stacks *stacks, int *count_a, int *count_b)
{
	int	middle;
	int	count;

	middle = list_middle_data(stacks->b_top, stacks->frame->data);
	count = stacks->frame->data;
	count -= list_count_lessmid(stacks->b_top, stacks->frame->data, middle);
	while (count > *count_a)
	{
		if (stacks->b_top->data >= middle)
		{
			stack_push(stacks, STACK_A);
			++*count_a;
			--stacks->frame->data;
		}
		else if (count == *count_a + 1 && stacks->b_top->next->data >= middle)
			stack_2elem_sort(stacks, STACK_B);
		else if (!stacks->frame->next && stacks->b_end->data >= middle)
			stack_rev_rotate(stacks, STACK_B);
		else
		{
			stack_rotate(stacks, STACK_B);
			++*count_b;
			--stacks->frame->data;
		}
	}
}

static void	stack_a_frame_split(t_stacks *stacks, int count)
{
	int	count_a;
	int	count_b;

	count_a = 0;
	count_b = 0;
	if (count <= 1)
		return ;
	else if (count == 2)
	{
		stack_2elem_sort(stacks, STACK_A);
		return ;
	}
	else if (count == 3)
	{
		stack_a3_sort(stacks);
		return ;
	}
	stack_a_frame_split_cycle(stacks, count, &count_a, &count_b);
	if (count_b)
		ft_list_push_front(&stacks->frame, count_b);
	count -= count_b;
	while (count_a-- > 0)
		stack_rev_rotate(stacks, STACK_A);
	stack_a_frame_split(stacks, count);
}

static void	stack_a_frame_split_cycle(t_stacks *stacks, int count, \
										int *count_a, int *count_b)
{
	int	mid;

	mid = list_middle_data(stacks->a_top, count);
	count = list_count_lessmid(stacks->a_top, count, mid);
	while (count > *count_b)
	{
		if (stacks->a_top->data < mid)
		{
			stack_push(stacks, STACK_B);
			++*count_b;
		}
		else if (count == *count_b + 1 && stacks->a_top->next->data < mid)
			stack_2elem_sort(stacks, STACK_A);
		else
		{
			stack_rotate(stacks, STACK_A);
			++*count_a;
		}
	}
}
