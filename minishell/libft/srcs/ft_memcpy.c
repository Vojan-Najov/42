/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 20:46:42 by ccartman          #+#    #+#             */
/*   Updated: 2021/04/26 20:26:08 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	if (n && (dst != src))
	{
		d = (char *) dst;
		s = (const char *) src;
		while (n--)
			*d++ = *s++;
	}
	return (dst);
}
