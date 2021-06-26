/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 14:56:36 by ccartman          #+#    #+#             */
/*   Updated: 2021/05/01 17:35:07 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_substrings(char const *s, char c);

static char		*ft_strndup(const char *s, size_t n);

static void		*ft_free_and_return_null(char **strs, size_t quantity);

char	**ft_split(char const *s, char c)
{
	char const	*ptr;
	size_t		count;
	size_t		i;
	char		**strs;

	count = ft_count_substrings(s, c);
	strs = (char **) malloc(sizeof(*strs) * (count + 1));
	if (!strs)
		return (NULL);
	i = -1;
	while (++i < count)
	{
		while (*s == c)
			++s;
		ptr = s;
		while (*s && (*s != c))
			++s;
		strs[i] = ft_strndup(ptr, s - ptr);
		if (!strs[i])
			return (ft_free_and_return_null(strs, i));
	}
	strs[count] = NULL;
	return (strs);
}

static size_t	ft_count_substrings(char const *s, char c)
{
	size_t	count;
	int		it_is_substring;

	count = 0;
	it_is_substring = 0;
	while (*s)
	{
		if (*s == c)
			it_is_substring = 0;
		else if (!it_is_substring)
		{
			++count;
			it_is_substring = 1;
		}
		++s;
	}
	return (count);
}

static char	*ft_strndup(const char *s, size_t n)
{
	size_t	len;
	char	*dup;

	len = ft_strlen(s);
	if (len < n)
		n = len;
	dup = (char *) malloc(sizeof(*dup) * (n + 1));
	if (!dup)
		return (NULL);
	ft_memcpy(dup, s, n);
	dup[n] = '\0';
	return (dup);
}

static void	*ft_free_and_return_null(char **strs, size_t quantity)
{
	size_t	i;

	i = 0;
	while (i < quantity)
	{
		free(strs[i]);
		++i;
	}
	free(strs);
	return (NULL);
}
