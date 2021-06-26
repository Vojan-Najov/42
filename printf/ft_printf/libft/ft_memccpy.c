/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 11:56:23 by ccartman          #+#    #+#             */
/*   Updated: 2021/04/26 21:59:20 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char			*d;
	const unsigned char		*s;
	unsigned char			smb;

	d = (unsigned char *) dst;
	s = (const unsigned char *) src;
	smb = (unsigned char) c;
	while (n--)
	{
		if (*s == smb)
		{
			*d = *s;
			return ((void *)++d);
		}
		*d++ = *s++;
	}		
	return ((void *) 0);
}
