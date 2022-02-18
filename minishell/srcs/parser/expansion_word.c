/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_word.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 19:36:06 by ccartman          #+#    #+#             */
/*   Updated: 2022/02/15 18:46:56 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	fill_new_word(char *new, char *old);

static char	*fill_new_word_cycle_body(char *new, char *old, size_t *idx_new, \
															int *expansion);

static char	*insert_variable_value(char *new, char *old, size_t *idx_new);

static char	*insert_env_variable_value(char *new, char *old, size_t *idx_new);

int	expansion_word(char **word)
{
	size_t	newlen;
	char	*new_word;
	char	*tmp;

	newlen = new_word_length(*word);
	new_word = (char *) malloc(sizeof(char) * (newlen + 1));
	new_word[newlen] = '\0';
	if (!new_word)
		return (PARSE_ERROR);
	if (!fill_new_word(new_word, *word))
	{
		free(new_word);
		return (PARSE_ERROR);
	}
	tmp = *word;
	*word = new_word;
	free(tmp);
	return (PARSE_SUCCESS);
}

static int	fill_new_word(char *new, char *old)
{
	size_t	idx_new;
	int		expan;

	expan = 1;
	idx_new = 0;
	while (*old)
	{
		old = fill_new_word_cycle_body(new, old, &idx_new, &expan);
		if (!old)
			return (PARSE_ERROR);
	}
	return (PARSE_SUCCESS);
}

static char	*fill_new_word_cycle_body(char *new, char *old, size_t *idx_new, \
															int *expansion)
{
	int	expan;

	expan = *expansion;
	if (expan == 1 && *old == '\"')
		expan = 0;
	else if (expan == 0 && *old == '\"')
		expan = 1;
	else if (expan == 1 && *old == '\'')
		expan = -1;
	else if (expan == -1 && *old == '\'')
		expan = 1;
	else if (expan != -1 && *old == '$' && old[1] && old[1] != '$' && \
					old[1] != '\'' && old[1] != '\"' && !ft_isblank(old[1]))
	{
		++old;
		old = insert_variable_value(new, old, idx_new);
		return (old);
	}
	*expansion = expan;
	if (ft_notadd(old, expan))
		return (++old);
	new[*idx_new] = *old;
	++*idx_new;
	return (++old);
}

static char	*insert_variable_value(char *new, char *old, size_t *idx_new)
{
	char	*value;
	size_t	len;

	if (*old == '?')
	{
		value = get_exit_status_str();
		len = ft_strlen(value);
		ft_memcpy(new + *idx_new, value, len);
		*idx_new += len;
		++old;
	}
	else
		old = insert_env_variable_value(new, old, idx_new);
	return (old);
}

static char	*insert_env_variable_value(char *new, char *old, size_t *idx_new)
{
	char	*value;
	char	*name;
	char	*old_start;
	size_t	len;

	old_start = old;
	while (ft_isalnum(*old) || *old == '_')
		++old;
	name = ft_strndup(old_start, old - old_start);
	if (!name)
		return (NULL);
	value = ft_getenv(name);
	free(name);
	if (value)
	{
		len = ft_strlen(value);
		ft_memcpy(new + *idx_new, value, len);
		*idx_new += len;
	}
	return (old);
}
