/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 19:19:02 by ccartman          #+#    #+#             */
/*   Updated: 2021/04/27 20:11:02 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	slen;
	char	*substr;

	slen = ft_strlen(s);
	if (start >= slen)
	{
		substr = (char *) malloc(sizeof(*substr));
		if (substr)
			*substr = '\0';
		return (substr);
	}
	if (slen - start < len)
		len = slen - start;
	while (start--)
		s++;
	substr = (char *) malloc(sizeof(*substr) * (len + 1));
	if (substr)
	{
		ft_memcpy(substr, s, len);
		substr[len] = '\0';
	}
	return (substr);
}
