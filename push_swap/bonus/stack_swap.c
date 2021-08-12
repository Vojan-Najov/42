#include "push_swap.h"

static void	list_swap(t_list **list);

void	stack_swap(t_stacks *stacks, int sign)
{
	if (sign == STACK_A)
	{
		list_swap(&stacks->a_top);
		stacks->a_end = ft_list_last(stacks->a_top);
	}
	else if (sign == STACK_B)
	{
		list_swap(&stacks->b_top);
		stacks->b_end = ft_list_last(stacks->b_top);
	}
	else if (sign == STACKS_AB)
	{
		list_swap(&stacks->a_top);
		stacks->a_end = ft_list_last(stacks->a_top);
		list_swap(&stacks->b_top);
		stacks->b_end = ft_list_last(stacks->b_top);
	}
}

static void	list_swap(t_list **list)
{
	t_list	*tmp;

	if (!*list || !(*list)->next)
		return ;
	tmp = *list;
	*list = (*list)->next;
	tmp->next = (*list)->next;
	(*list)->next = tmp;
}
