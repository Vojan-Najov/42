/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_into_words.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 19:40:37 by ccartman          #+#    #+#             */
/*   Updated: 2022/02/11 19:40:38 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	get_word_idx(const char *str, int *start);

int	split_into_words(const char *str, t_list **lst)
{
	int			start;
	int			end;
	char		*word;
	t_list		*new;

	start = 0;
	while (*str)
	{
		end = get_word_idx(str, &start);
		if (end > start)
		{
			word = ft_strndup(str + start, end - start);
			if (!word)
				return (malloc_list_error(lst));
			new = ft_lstnew(0, word);
			if (!new)
			{
				free(word);
				return (malloc_list_error(lst));
			}
			ft_lstadd_back(lst, new);
		}
		str += end;
	}
	return (PARSE_SUCCESS);
}

static int	get_word_idx(const char *str, int *start)
{
	int		i;
	int		inside_quote;
	char	quote;

	inside_quote = 0;
	i = 0;
	while (ft_isblank(str[i]))
		++i;
	*start = i;
	while (str[i])
	{
		if (!inside_quote && ft_isblank(str[i]))
			break ;
		else if (!inside_quote && (str[i] == '\"' || str[i] == '\''))
		{
			inside_quote = 1;
			quote = str[i];
		}
		else if (inside_quote && str[i] == quote)
			inside_quote = 0;
		++i;
	}
	return (i);
}
