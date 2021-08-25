/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 15:32:29 by ccartman          #+#    #+#             */
/*   Updated: 2021/08/18 17:02:12 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	list_rotate(t_list **list);

void	stack_rotate(t_stacks *stacks, int sign)
{
	if (sign == STACK_A)
	{
		list_rotate(&stacks->a_top);
		stacks->a_end = ft_list_last(stacks->a_top);
	}
	else if (sign == STACK_B)
	{
		list_rotate(&stacks->b_top);
		stacks->b_end = ft_list_last(stacks->b_top);
	}
	else if (sign == STACKS_AB)
	{
		list_rotate(&stacks->a_top);
		stacks->a_end = ft_list_last(stacks->a_top);
		list_rotate(&stacks->b_top);
		stacks->b_end = ft_list_last(stacks->b_top);
	}	
}

static void	list_rotate(t_list **list)
{
	t_list	*tmp;
	t_list	**pcur;

	if (!*list || !(*list)->next)
		return ;
	tmp = *list;
	*list = (*list)->next;
	pcur = list;
	while ((*pcur)->next)
		pcur = &(*pcur)->next;
	(*pcur)->next = tmp;
	tmp->next = NULL;
}
