/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_into_tokens.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 19:40:24 by ccartman          #+#    #+#             */
/*   Updated: 2022/02/11 19:40:26 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static size_t	find_token_idx(char *word);

static int		split_word(t_list **word_lst, size_t idx, t_list **begin_ptr);

int	split_into_tokens(t_list **lst)
{
	char	*word;
	size_t	idx;
	int		ret;
	t_list	**begin_ptr;

	ret = PARSE_SUCCESS;
	begin_ptr = lst;
	while (*lst)
	{
		word = (*lst)->word;
		idx = 0;
		idx = ft_istoken(word, 0);
		if (idx && word[idx])
			ret = split_word(lst, idx, begin_ptr);
		else if (!idx)
		{
			idx = find_token_idx(word);
			if (word[idx])
				ret = split_word(lst, idx, begin_ptr);
		}
		if (ret == PARSE_ERROR)
			return (PARSE_ERROR);
		lst = &((*lst)->next);
	}
	return (PARSE_SUCCESS);
}

static size_t	find_token_idx(char *word)
{
	int		inside_quote;
	char	quote;
	size_t	idx;

	inside_quote = 0;
	idx = 0;
	while (word[idx])
	{
		if (!inside_quote && (word[idx] == '\"' || word[idx] == '\''))
		{
			inside_quote = 1;
			quote = word[idx];
		}
		else if (inside_quote && word[idx] == quote)
			inside_quote = 0;
		else if (!inside_quote && ft_istoken(word + idx, 1))
			break ;
		++idx;
	}
	return (idx);
}

static int	split_word(t_list **word_lst, size_t idx, t_list **begin_ptr)
{
	t_list		*new;
	char		*word;
	char		*new_word;

	word = (*word_lst)->word;
	new_word = ft_strndup(word, idx);
	if (!new_word)
		return (malloc_list_error(begin_ptr));
	new = ft_lstnew(0, new_word);
	if (!new)
	{
		free(new_word);
		return (malloc_list_error(begin_ptr));
	}
	ft_memmove(word, word + idx, ft_strlen(word + idx) + 1);
	ft_lstadd_front(word_lst, new);
	return (PARSE_SUCCESS);
}
