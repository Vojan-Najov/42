/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 22:54:59 by ccartman          #+#    #+#             */
/*   Updated: 2021/04/30 23:40:05 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ptr;
	t_list	*new;

	ptr = NULL;
	while (lst)
	{
		new = ft_lstnew((*f)(lst->content));
		if (new)
			ft_lstadd_back(&ptr, new);
		else
		{
			ft_lstclear(&ptr, (*del));
			return (NULL);
		}
		lst = lst->next;
	}
	return (ptr);
}
