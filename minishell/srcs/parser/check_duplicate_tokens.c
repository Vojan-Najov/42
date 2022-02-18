/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplicate_tokens.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 19:35:10 by ccartman          #+#    #+#             */
/*   Updated: 2022/02/11 19:35:13 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	*check_duplicate_tokens(t_list *lst)
{
	int	flag;
	int	i;

	flag = 0;
	while (lst)
	{
		if ((lst->flag == PIPELINE) && (flag == PIPELINE))
			break ;
		if ((lst->flag & REDIRECT) && (flag & REDIRECT))
			break ;
		flag = lst->flag;
		lst = lst->next;
	}
	if (lst)
	{
		i = 0;
		while (ft_isdigit(lst->word[i]))
			++i;
		return (lst->word + i);
	}
	return (NULL);
}
