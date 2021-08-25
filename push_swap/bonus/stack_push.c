/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 15:32:08 by ccartman          #+#    #+#             */
/*   Updated: 2021/08/18 17:01:39 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	stack_push_a(t_stacks *stacks);

static void	stack_push_b(t_stacks *stacks);

void	stack_push(t_stacks *stacks, int sign)
{
	if (sign == STACK_A)
		stack_push_a(stacks);
	else if (sign == STACK_B)
		stack_push_b(stacks);
}

static void	stack_push_a(t_stacks *stacks)
{
	t_list	*elem;

	elem = stacks->b_top;
	if (!elem)
		return ;
	stacks->b_top = elem->next;
	if (!elem->next)
		stacks->b_end = NULL;
	elem->next = stacks->a_top;
	stacks->a_top = elem;
	stacks->a_end = ft_list_last(stacks->a_top);
}

static void	stack_push_b(t_stacks *stacks)
{
	t_list	*elem;

	elem = stacks->a_top;
	if (!elem)
		return ;
	stacks->a_top = elem->next;
	if (!elem->next)
		stacks->a_end = NULL;
	elem->next = stacks->b_top;
	stacks->b_top = elem;
	stacks->b_end = ft_list_last(stacks->b_top);
}
