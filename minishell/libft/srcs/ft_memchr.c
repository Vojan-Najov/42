/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 13:11:02 by ccartman          #+#    #+#             */
/*   Updated: 2021/04/26 21:00:49 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char		*ptr;
	unsigned char			smb;

	ptr = (const unsigned char *) s;
	smb = (unsigned char) c;
	while (n--)
		if (*ptr++ == smb)
			return ((void *)--ptr);
	return ((void *) 0);
}
