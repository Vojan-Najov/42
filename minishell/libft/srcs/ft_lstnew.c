/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 21:00:21 by ccartman          #+#    #+#             */
/*   Updated: 2021/04/29 21:16:06 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(int flag, char *word)
{
	t_list	*lstnew;

	lstnew = (t_list *) malloc(sizeof(*lstnew));
	if (lstnew)
	{
		lstnew->flag = flag;
		lstnew->word = word;
		lstnew->next = NULL;
	}
	return (lstnew);
}
