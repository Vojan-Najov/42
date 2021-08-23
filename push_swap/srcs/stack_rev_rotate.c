/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rev_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 13:38:26 by ccartman          #+#    #+#             */
/*   Updated: 2021/08/17 13:38:29 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	list_rev_rotate(t_list **list);

void	stack_rev_rotate(t_stacks *stacks, int sign)
{
	if (sign == STACK_A)
	{
		list_rev_rotate(&stacks->a_top);
		stacks->a_end = ft_list_last(stacks->a_top);
		ft_strjoin_and_free_src(&stacks->instructions, REV_ROTATE_A);
	}
	else if (sign == STACK_B)
	{
		list_rev_rotate(&stacks->b_top);
		stacks->b_end = ft_list_last(stacks->b_top);
		ft_strjoin_and_free_src(&stacks->instructions, REV_ROTATE_B);
	}
	else if (sign == STACKS_AB)
	{
		list_rev_rotate(&stacks->a_top);
		stacks->a_end = ft_list_last(stacks->a_top);
		list_rev_rotate(&stacks->b_top);
		stacks->b_end = ft_list_last(stacks->b_top);
		ft_strjoin_and_free_src(&stacks->instructions, REV_ROTATE_AB);
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
