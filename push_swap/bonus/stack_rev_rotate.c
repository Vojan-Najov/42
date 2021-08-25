/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rev_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 15:32:20 by ccartman          #+#    #+#             */
/*   Updated: 2021/08/18 17:01:58 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	list_rev_rotate(t_list **list);

void	stack_rev_rotate(t_stacks *stacks, int sign)
{
	if (sign == STACK_A)
	{
		list_rev_rotate(&stacks->a_top);
		stacks->a_end = ft_list_last(stacks->a_top);
	}
	else if (sign == STACK_B)
	{
		list_rev_rotate(&stacks->b_top);
		stacks->b_end = ft_list_last(stacks->b_top);
	}
	else if (sign == STACKS_AB)
	{
		list_rev_rotate(&stacks->a_top);
		stacks->a_end = ft_list_last(stacks->a_top);
		list_rev_rotate(&stacks->b_top);
		stacks->b_end = ft_list_last(stacks->b_top);
	}	
}

static void	list_rev_rotate(t_list **list)
{
	t_list	*tmp;
	t_list	**pcur;

	if (!*list || !(*list)->next)
		return ;
	pcur = list;
	while (*pcur)
	{
		if ((*pcur)->next == NULL)
		{
			tmp = *pcur;
			*pcur = NULL;
		}
		else
			pcur = &(*pcur)->next;
	}
	tmp->next = *list;
	*list = tmp;
}
