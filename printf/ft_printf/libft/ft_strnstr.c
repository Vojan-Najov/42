/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 17:08:58 by ccartman          #+#    #+#             */
/*   Updated: 2021/04/29 15:47:51 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		haystack_len;
	size_t		needle_len;
	size_t		i;
	size_t		j;

	haystack_len = ft_strlen(haystack);
	needle_len = ft_strlen(needle);
	if (!needle_len)
		return ((char *) haystack);
	if (len > haystack_len)
		len = haystack_len;
	if (needle_len > len)
		return ((void *) 0);
	i = 0;
	while (i <= len - needle_len)
	{
		j = 0;
		while (j < needle_len && haystack[i + j] == needle[j])
			++j;
		if (j == needle_len)
			return ((char *) haystack + i);
		++i;
	}
	return ((void *) 0);
}
