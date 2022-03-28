/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 12:15:46 by ccartman          #+#    #+#             */
/*   Updated: 2021/04/26 20:40:30 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const char	*s;
	char		*d;

	s = (const char *) src;
	d = (char *) dst;
	if (s < d)
	{
		s += len;
		d += len;
		while (len--)
			*--d = *--s;
	}
	else if (s > d)
		while (len--)
			*d++ = *s++;
	return (dst);
}
