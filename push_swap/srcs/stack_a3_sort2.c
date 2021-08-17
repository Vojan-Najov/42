#include "push_swap.h"

static void	stack_a3_sort_part2(t_stacks *stacks, int a2, int a3, int flag);

static void	stack_a3_sort_part3(t_stacks *stacks, int a2, int a3, int flag);

void	stack_a3_sort(t_stacks *stacks)
{
	int	a1;
	int	a2;
	int	a3;
	int	flag;
	int	flag2;

	a1 = stacks->a_top->data;
	a2 = stacks->a_top->next->data;
	a3 = stacks->a_top->next->next->data;
	if (ft_list_size(stacks->b_top) > 1 && \
	stacks->b_top->data < stacks->b_top->next->data)
		flag = 1;
	else
		flag = 0;
	if (ft_list_size(stacks->b_top) > 2 && \
	stacks->b_top->next->data < stacks->b_top->next->next->data)
		flag2 = 1;
	else
		flag2 = 0;

	if (a1 < a2 && a2 > a3 && a1 < a3)
	{
		if (flag2)
			stack_rotate(stacks, STACKS_AB);
		else
			stack_rotate(stacks, STACK_A);
		if (flag || flag2)
			stack_swap(stacks, STACKS_AB);
		else
			stack_swap(stacks, STACK_A);
		if (flag2)
			stack_rev_rotate(stacks, STACKS_AB);
		else
			stack_rev_rotate(stacks, STACK_A);
	}
	else
		stack_a3_sort_part2(stacks, a2, a3, flag);
}

static void	stack_a3_sort_part2(t_stacks *stacks, int a2, int a3, int flag)
{
	int	a1;
	int flag2;

	if (ft_list_size(stacks->b_top) > 2 && \
	stacks->b_top->next->data < stacks->b_top->next->next->data)
		flag2 = 1;
	else
		flag2 = 0;

	a1 = stacks->a_top->data;
	if (a1 > a2 && a2 < a3 && a1 < a3)
	{
		if (flag)
			stack_swap(stacks, STACKS_AB);
		else
			stack_swap(stacks, STACK_A);
	}
	else if (a1 < a2 && a2 > a3 && a1 > a3)
	{
		if (flag2)
			stack_rotate(stacks, STACKS_AB);
		else
			stack_rotate(stacks, STACK_A);
		if (flag || flag2)
			stack_swap(stacks, STACKS_AB);
		else
			stack_swap(stacks, STACK_A);
		if (flag2)
			stack_rev_rotate(stacks, STACKS_AB);
		else
			stack_rev_rotate(stacks, STACK_A);
		if (ft_list_size(stacks->b_top) > 1 && \
		stacks->b_top->data < stacks->b_top->next->data)
			flag = 1;
		else
			flag = 0;
		if (flag)
			stack_swap(stacks, STACKS_AB);
		else
			stack_swap(stacks, STACK_A);
	}	
	else
		stack_a3_sort_part3(stacks, a2, a3, flag);
}

static void	stack_a3_sort_part3(t_stacks *stacks, int a2, int a3, int flag)
{
	int	a1;
	int flag2;

	if (ft_list_size(stacks->b_top) > 2 && \
	stacks->b_top->next->data < stacks->b_top->next->next->data)
		flag2 = 1;
	else
		flag2 = 0;

	a1 = stacks->a_top->data;
	if (a1 > a2 && a2 < a3 && a1 > a3)
	{
		if (flag)
			stack_swap(stacks, STACKS_AB);
		else
			stack_swap(stacks, STACK_A);
		if (flag2)
			stack_rotate(stacks, STACKS_AB);
		else
			stack_rotate(stacks, STACK_A);
		if (flag2)
			stack_swap(stacks, STACKS_AB);
		else
			stack_swap(stacks, STACK_A);
		if (flag2)
			stack_rev_rotate(stacks, STACKS_AB);
		else
			stack_rev_rotate(stacks, STACK_A);
	}
	else if (a1 > a2 && a2 > a3 && a1 > a3)
	{
		if (flag)
			stack_swap(stacks, STACKS_AB);
		else
			stack_swap(stacks, STACK_A);
		if (ft_list_size(stacks->b_top) > 2 && \
		stacks->b_top->next->data < stacks->b_top->next->next->data)
			flag2 = 1;
		else
			flag2 = 0;

		if (flag2)
			stack_rotate(stacks, STACKS_AB);
		else
			stack_rotate(stacks, STACK_A);
		if (flag2)
			stack_swap(stacks, STACKS_AB);
		else
			stack_swap(stacks, STACK_A);
		if (flag2)
			stack_rev_rotate(stacks, STACKS_AB);
		else
			stack_rev_rotate(stacks, STACK_A);
		if (ft_list_size(stacks->b_top) > 1 && \
		stacks->b_top->data < stacks->b_top->next->data)
			flag = 1;
		else
			flag = 0;
		if (flag)
			stack_swap(stacks, STACKS_AB);
		else
			stack_swap(stacks, STACK_A);
	}
}
