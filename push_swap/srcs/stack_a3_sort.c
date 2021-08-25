/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a3_sort3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 14:11:37 by ccartman          #+#    #+#             */
/*   Updated: 2021/08/17 15:17:13 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	stack_a3_sort_part2(t_stacks *stacks, int a2, int a3, int flag);

static void	stack_a3_sort_part3(t_stacks *stacks, int a3, int flag2, int flag3);

static void	stack_a3_sort_part4(t_stacks *stacks, int a3, int flag2, int flag3);

static void	stack_a3_sort_part5(t_stacks *stacks, int flag2, int flag3);

void	stack_a3_sort(t_stacks *stacks)
{
	int	a1;
	int	a2;
	int	a3;
	int	flag2;

	a1 = stacks->a_top->data;
	a2 = stacks->a_top->next->data;
	a3 = stacks->a_top->next->next->data;
	flag2 = (ft_list_size(stacks->b_top) > 1 && \
	stacks->b_top->data < stacks->b_top->next->data);
	if (a1 < a2 && a2 < a3 && a1 < a3)
		return ;
	if (a1 > a2 && a2 < a3 && a1 < a3)
	{
		if (flag2)
			stack_swap(stacks, STACKS_AB);
		else
			stack_swap(stacks, STACK_A);
	}
	else
		stack_a3_sort_part2(stacks, a2, a3, flag2);
}

static void	stack_a3_sort_part2(t_stacks *stacks, int a2, int a3, int flag2)
{
	int	a1;
	int	flag3;

	a1 = stacks->a_top->data;
	flag3 = (ft_list_size(stacks->b_top) > 2 && \
			stacks->b_top->next->data < stacks->b_top->next->next->data);
	if (a1 < a2 && a2 > a3 && a1 < a3)
	{
		if (flag3)
			stack_rotate(stacks, STACKS_AB);
		else
			stack_rotate(stacks, STACK_A);
		if (flag3 || flag2)
			stack_swap(stacks, STACKS_AB);
		else
			stack_swap(stacks, STACK_A);
		if (flag3)
			stack_rev_rotate(stacks, STACKS_AB);
		else
			stack_rev_rotate(stacks, STACK_A);
	}
	else
		stack_a3_sort_part3(stacks, a3, flag2, flag3);
}

static void	stack_a3_sort_part3(t_stacks *stacks, int a3, int flag2, int flag3)
{
	int	a1;
	int	a2;

	a1 = stacks->a_top->data;
	a2 = stacks->a_top->next->data;
	if (a1 < a2 && a2 > a3 && a1 > a3)
	{
		if (flag3)
			stack_rotate(stacks, STACKS_AB);
		else
			stack_rotate(stacks, STACK_A);
		if (flag2 || flag3)
			stack_swap(stacks, STACKS_AB);
		else
			stack_swap(stacks, STACK_A);
		if (flag3)
			stack_rev_rotate(stacks, STACKS_AB);
		else
			stack_rev_rotate(stacks, STACK_A);
		stack_swap(stacks, STACK_A);
	}
	else
		stack_a3_sort_part4(stacks, a3, flag2, flag3);
}

static void	stack_a3_sort_part4(t_stacks *stacks, int a3, int flag2, int flag3)
{
	if (stacks->a_top->data > stacks->a_top->next->data && \
		stacks->a_top->next->data < a3 && stacks->a_top->data > a3)
	{
		if (flag2)
			stack_swap(stacks, STACKS_AB);
		else
			stack_swap(stacks, STACK_A);
		flag3 = (ft_list_size(stacks->b_top) > 2 && \
				stacks->b_top->next->data < stacks->b_top->next->next->data);
		if (flag3)
		{
			stack_rotate(stacks, STACKS_AB);
			stack_swap(stacks, STACKS_AB);
			stack_rev_rotate(stacks, STACKS_AB);
		}
		else
		{
			stack_rotate(stacks, STACK_A);
			stack_swap(stacks, STACK_A);
			stack_rev_rotate(stacks, STACK_A);
		}
	}
	else
		stack_a3_sort_part5(stacks, flag2, flag3);
}

/* Case a1 > a2 && a2 > a3 && a1 > a3 */

static void	stack_a3_sort_part5(t_stacks *stacks, int flag2, int flag3)
{
	if (flag2)
		stack_swap(stacks, STACKS_AB);
	else
		stack_swap(stacks, STACK_A);
	flag3 = (ft_list_size(stacks->b_top) > 2 && \
			stacks->b_top->next->data < stacks->b_top->next->next->data);
	if (flag3)
	{
		stack_rotate(stacks, STACKS_AB);
		stack_swap(stacks, STACKS_AB);
		stack_rev_rotate(stacks, STACKS_AB);
	}
	else
	{
		stack_rotate(stacks, STACK_A);
		stack_swap(stacks, STACK_A);
		stack_rev_rotate(stacks, STACK_A);
	}
	flag2 = (ft_list_size(stacks->b_top) > 1 && \
		stacks->b_top->data < stacks->b_top->next->data);
	if (flag2)
		stack_swap(stacks, STACKS_AB);
	else
		stack_swap(stacks, STACK_A);
}
