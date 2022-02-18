/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_into_commands.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 19:40:12 by ccartman          #+#    #+#             */
/*   Updated: 2022/02/11 19:40:14 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	split_into_commands_cycle(t_list **lsts, t_list **lst);

t_list	**split_into_commands(t_list **lst)
{
	size_t	i;
	t_list	*tmp;
	t_list	**lsts;

	i = 1;
	tmp = *lst;
	while (tmp)
	{
		if (tmp->flag == PIPELINE)
			++i;
		tmp = tmp->next;
	}
	lsts = (t_list **) malloc(sizeof(t_list *) * (i + 1));
	if (!lsts)
	{
		malloc_list_error(lst);
		return (NULL);
	}
	lsts[i] = NULL;
	split_into_commands_cycle(lsts, lst);
	return (lsts);
}	

static void	split_into_commands_cycle(t_list **lsts, t_list **lst)
{
	size_t	i;
	t_list	*tmp;

	i = 0;
	while (*lst)
	{
		lsts[i] = *lst;
		while (*lst && (*lst)->flag != PIPELINE)
			lst = &(*lst)->next;
		if (*lst)
		{
			tmp = (*lst)->next;
			free((*lst)->word);
			free(*lst);
			*lst = NULL;
			lst = &tmp;
		}
		++i;
	}	
}
