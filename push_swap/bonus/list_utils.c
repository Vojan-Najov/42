/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 15:31:53 by ccartman          #+#    #+#             */
/*   Updated: 2021/08/18 17:01:22 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_list_issorted(t_list *list)
{
	int	n;

	n = INT_MIN;
	while (list)
	{
		if (list->data < n)
			return (0);
		n = list->data;
		list = list->next;
	}
	return (1);
}

size_t	ft_list_size(t_list *list)
{
	size_t	count;

	count = 0;
	while (list)
	{
		++count;
		list = list->next;
	}
	return (count);
}

void	ft_list_remove(t_list **list, size_t n)
{
	t_list	*tmp;

	while (*list && n-- > 0)
		list = &(*list)->next;
	if (!*list)
		return ;
	tmp = *list;
	*list = (*list)->next;
	free(tmp);
}
