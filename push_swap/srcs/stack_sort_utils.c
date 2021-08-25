/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort_utils1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 13:40:40 by ccartman          #+#    #+#             */
/*   Updated: 2021/08/17 13:40:43 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	stack_a3only_sort_part2(t_stacks *stacks, int a1, int a2, int flag);

void	stack_2elem_sort(t_stacks *stacks, int sign)
{
	size_t	size;

	if (sign == STACK_A)
	{
		if (stacks->a_top->data > stacks->a_top->next->data)
		{
			size = ft_list_size(stacks->b_top);
			if (size > 1 && stacks->b_top->data < stacks->b_top->next->data)
				stack_swap(stacks, STACKS_AB);
			else
				stack_swap(stacks, STACK_A);
		}
	}
	else if (sign == STACK_B)
	{
		if (stacks->b_top->data < stacks->b_top->next->data)
		{
			size = ft_list_size(stacks->a_top);
			if (size > 1 && stacks->a_top->data > stacks->a_top->next->data)
				stack_swap(stacks, STACKS_AB);
			else
				stack_swap(stacks, STACK_B);
		}
	}
}

void	stack_a3only_sort(t_stacks *stacks)
{
	int	a1;
	int	a2;
	int	a3;
	int	flag;

	a1 = stacks->a_top->data;
	a2 = stacks->a_top->next->data;
	a3 = stacks->a_top->next->next->data;
	if (ft_list_size(stacks->b_top) > 1 && \
	stacks->b_top->data < stacks->b_top->next->data)
		flag = 1;
	else
		flag = 0;
	if (a1 < a2 && a2 < a3 && a1 < a3)
		return ;
	else if (a1 < a2 && a2 > a3 && a1 < a3)
	{
		stack_rev_rotate(stacks, STACK_A);
		if (flag)
			stack_swap(stacks, STACKS_AB);
		else
			stack_swap(stacks, STACK_A);
	}
	else
		stack_a3only_sort_part2(stacks, a1, a2, flag);
}

static void	stack_a3only_sort_part2(t_stacks *stacks, int a1, int a2, int flag)
{
	int	a3;

	a3 = stacks->a_top->next->next->data;
	if (a1 > a2 && a2 < a3 && a1 < a3)
	{	
		if (flag)
			stack_swap(stacks, STACKS_AB);
		else
			stack_swap(stacks, STACK_A);
	}
	else if (a1 < a2 && a2 > a3 && a1 > a3)
		stack_rev_rotate(stacks, STACK_A);
	else if (a1 > a2 && a2 < a3 && a1 > a3)
		stack_rotate(stacks, STACK_A);
	else if (a1 > a2 && a2 > a3 && a1 > a3)
	{
		stack_rotate(stacks, STACK_A);
		if (flag)
			stack_swap(stacks, STACKS_AB);
		else
			stack_swap(stacks, STACK_A);
	}
}
