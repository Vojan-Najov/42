/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 16:09:49 by ccartman          #+#    #+#             */
/*   Updated: 2021/04/26 22:56:08 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;
	char	smb;

	ptr = (char *) s;
	smb = (char) c;
	while (*ptr)
		if (*ptr++ == smb)
			return (--ptr);
	if (smb == '\0')
		return (ptr);
	else
		return ((void *) 0);
}
