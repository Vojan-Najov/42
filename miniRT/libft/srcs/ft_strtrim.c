/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 20:35:10 by ccartman          #+#    #+#             */
/*   Updated: 2021/04/29 20:10:59 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	const char		*begin;
	const char		*end;
	char			*str;
	size_t			len;

	begin = s1;
	while (ft_strchr(set, *begin) && *begin)
		++begin;
	if (!*begin)
		return (ft_calloc(1, sizeof(*str)));
	end = s1 + ft_strlen(s1) - 1;
	while (ft_strchr(set, *end) && (end >= begin))
		--end;
	len = end - begin + 1;
	str = (char *) malloc(sizeof(*str) * (len + 1));
	if (str)
	{
		str = ft_memcpy(str, begin, len);
		str[len] = '\0';
	}
	return (str);
}
