/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 13:26:15 by ccartman          #+#    #+#             */
/*   Updated: 2021/04/26 21:09:36 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char		*ptr1;
	const unsigned char		*ptr2;

	ptr1 = (const unsigned char *) s1;
	ptr2 = (const unsigned char *) s2;
	while (n--)
		if (*ptr1++ != *ptr2++)
			return (*--ptr1 - *--ptr2);
	return (0);
}
