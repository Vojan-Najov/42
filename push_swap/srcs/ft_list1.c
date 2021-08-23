/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 13:18:13 by ccartman          #+#    #+#             */
/*   Updated: 2021/08/17 13:18:30 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*ft_create_elem(int num)
{
	t_list	*elem;

	elem = (t_list *) malloc(sizeof(t_list));
	if (elem)
	{
		elem->data = num;
		elem->next = NULL;
	}
	return (elem);
}

t_list	*ft_list_last(t_list *list)
{
	if (!list)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

void	ft_list_push_front(t_list **list, int num)
{
	t_list	*elem;

	elem = ft_create_elem(num);
	if (!elem)
		exit(EXIT_FAILURE);
	elem->next = *list;
	*list = elem;
}

void	ft_list_push_back(t_list **list, int num)
{
	t_list	*elem;

	elem = ft_create_elem(num);
	if (!elem)
		exit(EXIT_FAILURE);
	if (!*list)
	{
		*list = elem;
		return ;
	}
	while ((*list)->next)
		list = &(*list)->next;
	(*list)->next = elem;
}

void	ft_list_clear(t_list *a)
{
	t_list	*tmp;

	while (a)
	{
		tmp = a;
		a = a->next;
		free(tmp);
	}
}
