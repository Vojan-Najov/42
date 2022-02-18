/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counters.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 19:35:45 by ccartman          #+#    #+#             */
/*   Updated: 2022/02/11 19:35:47 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

size_t	count_commands(t_list **lsts)
{
	size_t	n;

	n = 0;
	while (*lsts)
	{
		++n;
		++lsts;
	}
	return (n);
}

size_t	count_redirects(t_list *lst)
{
	size_t	n;

	n = 0;
	while (lst)
	{
		if (lst->flag & REDIRECT)
			++n;
		lst = lst->next;
	}
	return (n);
}

size_t	count_args(t_list *lst)
{
	size_t	n;

	n = 0;
	while (lst)
	{
		if (lst->flag & ARGUMENT)
			++n;
		lst = lst->next;
	}
	return (n);
}
