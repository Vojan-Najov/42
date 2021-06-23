/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 13:54:15 by ccartman          #+#    #+#             */
/*   Updated: 2021/04/26 22:09:45 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t		n;
	char		*d;
	const char	*s;

	n = dstsize;
	d = (char *) dst;
	s = (const char *) src;
	if (n && --n)
	{
		while (n)
		{
			*d++ = *s++;
			if (*(d - 1) == 0)
				break ;
			--n;
		}
	}
	if (n == 0)
	{
		if (dstsize)
			*d = '\0';
		while (*s++)
			;
	}
	return (s - 1 - src);
}
