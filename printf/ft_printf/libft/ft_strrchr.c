/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 16:30:18 by ccartman          #+#    #+#             */
/*   Updated: 2021/04/26 22:56:22 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	char	*str;
	char	smb;

	smb = (char) c;
	ptr = (void *) 0;
	str = (char *) s;
	while (*str)
	{
		if (*str == smb)
			ptr = str;
		++str;
	}
	if (smb == '\0')
		ptr = str;
	return (ptr);
}
