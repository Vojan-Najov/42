/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_words_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 19:39:54 by ccartman          #+#    #+#             */
/*   Updated: 2022/02/11 19:39:56 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	set_words_flags(t_list *lst)
{
	int	i;

	while (lst)
	{
		if (!ft_istoken(lst->word, 0))
			lst->flag = ARGUMENT;
		else
		{
			i = 0;
			while (ft_isdigit(lst->word[i]))
				++i;
			if (lst->word[i] == '|')
				lst->flag = PIPELINE;
			else if (!ft_strcmp(lst->word + i, "<<"))
				lst->flag = REDIRECT | REDIRECT_HEREDOC;
			else if (!ft_strcmp(lst->word + i, ">>"))
				lst->flag = REDIRECT | REDIRECT_APPEND;
			else if (lst->word[i] == '<')
				lst->flag = REDIRECT | REDIRECT_INPUT;
			else if (lst->word[i] == '>')
				lst->flag = REDIRECT | REDIRECT_OUTPUT;
		}
		lst = lst->next;
	}
}
