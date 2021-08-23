/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 13:41:36 by ccartman          #+#    #+#             */
/*   Updated: 2021/08/17 13:41:38 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	list_swap(t_list **list);

void	stack_swap(t_stacks *stacks, int sign)
{
	if (sign == STACK_A)
	{
		list_swap(&stacks->a_top);
		stacks->a_end = ft_list_last(stacks->a_top);
		ft_strjoin_and_free_src(&stacks->instructions, SWAP_A);
	}
	else if (sign == STACK_B)
	{
		list_swap(&stacks->b_top);
		stacks->b_end = ft_list_last(stacks->b_top);
		ft_strjoin_and_free_src(&stacks->instructions, SWAP_B);
	}
	else if (sign == STACKS_AB)
	{
		list_swap(&stacks->a_top);
		stacks->a_end = ft_list_last(stacks->a_top);
		list_swap(&stacks->b_top);
		stacks->b_end = ft_list_last(stacks->b_top);
		ft_strjoin_and_free_src(&stacks->instructions, SWAP_AB);
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
