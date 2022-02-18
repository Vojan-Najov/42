/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_word_length.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 19:39:07 by ccartman          #+#    #+#             */
/*   Updated: 2022/02/15 18:49:33 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void		new_word_length_cycle_body(char *str, size_t *idx, \
										size_t *length, int *expansion);

static size_t	value_length(char *str, size_t *idx);

static size_t	exit_status_str_length(void);

size_t	new_word_length(char *str)
{
	size_t	len;
	size_t	i;
	int		expan;

	i = 0;
	len = 0;
	expan = 1;
	while (str[i])
	{
		new_word_length_cycle_body(str, &i, &len, &expan);
		++i;
	}
	return (len);
}

int	ft_notadd(char *str, int expan)
{
	if (str[0] == '\"' && expan != -1)
		return (1);
	if (str[0] == '\'' && expan != 0)
		return (1);
	if (str[0] == '$' && str[1] == '\'' && expan == 1)
		return (1);
	if (str[0] == '$' && str[1] == '\"' && expan == 1)
		return (1);
	return (0);
}

static void	new_word_length_cycle_body(char *str, size_t *idx, \
										size_t *length, int *expansion)
{
	size_t	i;
	int		expan;

	i = *idx;
	expan = *expansion;
	if (expan == 1 && str[i] == '\"')
		expan = 0;
	else if (expan == 0 && str[i] == '\"')
		expan = 1;
	else if (expan == 1 && str[i] == '\'')
		expan = -1;
	else if (expan == -1 && str[i] == '\'')
		expan = 1;
	else if (expan != -1 && str[i] == '$' && str[i + 1] && \
			str[i + 1] != '\"' && str[i + 1] != '\'' && !ft_isblank(str[i + 1]))
	{
		*idx = i + 1;
		*length += value_length(str, idx);
		return ;
	}
	*expansion = expan;
	if (ft_notadd(str + i, expan))
		return ;
	++*length;
}

static size_t	value_length(char *str, size_t *idx)
{
	char	*name;
	char	*value;
	size_t	len;
	size_t	i;

	len = 0;
	i = *idx;
	if (str[i] == '?')
		return (exit_status_str_length());
	while (ft_isalnum(str[i]) || str[i] == '_')
		++i;
	name = ft_substr(str, *idx, i - *idx);
	if (!name)
	{
		print_str_error("malloc");
		return (0);
	}
	value = ft_getenv(name);
	free(name);
	if (value)
		len = ft_strlen(value);
	*idx = i - 1;
	return (len);
}

static size_t	exit_status_str_length(void)
{
	char	*status_str;
	size_t	len;

	status_str = get_exit_status_str();
	len = ft_strlen(status_str);
	return (len);
}
