/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 13:18:40 by ccartman          #+#    #+#             */
/*   Updated: 2021/08/17 13:32:06 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	list_middle_data(t_list *list, size_t size)
{
	int	*array;
	int	i;
	int	mid;

	i = 0;
	array = (int *) malloc(sizeof(int) * size);
	while (size-- && list)
	{
		array[i] = list->data;
		list = list->next;
		++i;
	}
	heap_sort(array, i);
	mid = array[i / 2];
	free(array);
	return (mid);
}

size_t	list_count_lessmid(t_list *list, size_t size, int mid)
{
	size_t	count;

	count = 0;
	while (size-- && list)
	{
		if (list->data < mid)
			++count;
		list = list->next;
	}
	return (count);
}
