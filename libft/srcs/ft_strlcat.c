/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 14:52:03 by ccartman          #+#    #+#             */
/*   Updated: 2021/05/01 15:50:24 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char		*d;
	const char	*s;
	size_t		size;
	size_t		dst_len;

	d = (char *) dst;
	s = (const char *) src;
	size = dstsize;
	while (size-- && *d)
		d++;
	dst_len = d - dst;
	size = dstsize - dst_len;
	if (!size)
		return (dst_len + ft_strlen(s));
	while (*s)
	{
		if (size != 1)
		{
			*d++ = *s;
			--size;
		}
		s++;
	}
	*d = '\0';
	return (dst_len + (s - src));
}
