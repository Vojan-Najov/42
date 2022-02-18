/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 19:39:41 by ccartman          #+#    #+#             */
/*   Updated: 2022/02/11 19:39:43 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	check_unclosed_quote(const char *str);

static int	check_blank_str(const char *str);

int	preparse(const char *str)
{
	int	ret;

	ret = check_blank_str(str);
	if (ret)
		return (PREPARSE_BLANK);
	ret = check_unclosed_quote(str);
	if (ret)
	{
		write(STDERR_FILENO, g_quote_err, sizeof(g_quote_err) - 1);
		return (PREPARSE_ERROR);
	}
	return (PREPARSE_SUCCESS);
}

static int	check_blank_str(const char *str)
{
	int	isblank;

	isblank = 1;
	while (*str)
	{
		if (!ft_isblank(*str))
			isblank = 0;
		++str;
	}
	if (isblank)
		return (PREPARSE_BLANK);
	return (PREPARSE_SUCCESS);
}

static int	check_unclosed_quote(const char *str)
{
	char	quote;

	while (*str)
	{
		if (*str == '\'' || *str == '\"')
		{
			quote = *str;
			while (*++str && *str != quote)
				;
			if (!*str)
				return (PREPARSE_ERROR);
		}
		++str;
	}
	return (PREPARSE_SUCCESS);
}
