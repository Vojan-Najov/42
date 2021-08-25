/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b3_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 13:37:54 by ccartman          #+#    #+#             */
/*   Updated: 2021/08/17 13:37:57 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	stack_b3_sort_part2(t_stacks *stacks, int b1, int b2, int b3);

static void	stack_b3_sort_part3(t_stacks *stacks, int b1, int b2, int b3);

void	stack_b3_sort(t_stacks *stacks)
{
	int	b1;
	int	b2;
	int	b3;

	b1 = stacks->b_top->data;
	b2 = stacks->b_top->next->data;
	b3 = stacks->b_top->next->next->data;
	if (b1 < b2 && b2 < b3 && b1 < b3)
	{
		stack_rotate(stacks, STACK_B);
		stack_swap(stacks, STACK_B);
		stack_push(stacks, STACK_A);
		stack_push(stacks, STACK_A);
		if (ft_list_size(stacks->b_top) > 1)
			stack_rev_rotate(stacks, STACK_B);
		stack_push(stacks, STACK_A);
	}	
	else if (b1 > b2 && b2 > b3 && b1 > b3)
	{
		stack_push(stacks, STACK_A);
		stack_push(stacks, STACK_A);
		stack_push(stacks, STACK_A);
	}
	else
		stack_b3_sort_part2(stacks, b1, b2, b3);
}

static void	stack_b3_sort_part2(t_stacks *stacks, int b1, int b2, int b3)
{
	if (b1 < b2 && b2 > b3 && b1 < b3)
	{
		stack_rotate(stacks, STACK_B);
		stack_push(stacks, STACK_A);
		stack_push(stacks, STACK_A);
		if (ft_list_size(stacks->b_top) > 1)
			stack_rev_rotate(stacks, STACK_B);
		stack_push(stacks, STACK_A);
	}	
	else if (b1 > b2 && b2 < b3 && b1 < b3)
	{
		stack_push(stacks, STACK_A);
		stack_swap(stacks, STACK_B);
		stack_push(stacks, STACK_A);
		stack_swap(stacks, STACK_A);
		stack_push(stacks, STACK_A);
	}
	else
		stack_b3_sort_part3(stacks, b1, b2, b3);
}

static void	stack_b3_sort_part3(t_stacks *stacks, int b1, int b2, int b3)
{
	if (b1 < b2 && b2 > b3 && b1 > b3)
	{
		stack_swap(stacks, STACK_B);
		stack_push(stacks, STACK_A);
		stack_push(stacks, STACK_A);
		stack_push(stacks, STACK_A);
	}
	if (b1 > b2 && b2 < b3 && b1 > b3)
	{
		stack_push(stacks, STACK_A);
		stack_swap(stacks, STACK_B);
		stack_push(stacks, STACK_A);
		stack_push(stacks, STACK_A);
	}
}
