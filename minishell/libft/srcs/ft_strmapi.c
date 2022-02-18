/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 16:58:11 by ccartman          #+#    #+#             */
/*   Updated: 2021/04/29 17:22:57 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	size;
	size_t	i;

	size = ft_strlen(s);
	str = (char *) malloc(sizeof(*str) * (size + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < size)
	{
		str[i] = (*f)((unsigned int) i, s[i]);
		++i;
	}
	str[size] = '\0';
	return (str);
}
