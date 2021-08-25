/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dupx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 17:28:38 by ccartman          #+#    #+#             */
/*   Updated: 2021/03/10 15:36:34 by malison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char			*ft_dupx(char *str, int *size)
{
	int		n;
	char	*dupx;

	n = *size;
	dupx = malloc(sizeof(char) * (n + n / 2 + 1));
	if (dupx)
	{
		n = -1;
		while (++n < *size)
			dupx[n] = str[n];
	}
	free(str);
	*size = n + n / 2 + 1;
	return (dupx);
}

int				ft_strlen(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
		;
	return (i);
}

unsigned int	ft_atoi(char *str)
{
	unsigned int	map_size;
	int				i;
	int				l;

	i = 0;
	map_size = 0;
	l = ft_strlen(str);
	if (l < 4)
		return (0);
	while ((str[i] >= '0') && (str[i] <= '9') && (i < (l - 3)))
	{
		map_size = map_size * 10 + (str[i] - '0');
		i++;
	}
	if (i != l - 3)
		map_size = 0;
	return (map_size);
}

int				ft_check_symbs(char ce, char co, char cf)
{
	if (!(32 < ce && ce < 127))
		return (0);
	if (!(32 < co && co < 127))
		return (0);
	if (!(32 < cf && cf < 127))
		return (0);
	if (ce == co || co == cf || ce == cf)
		return (0);
	return (1);
}
