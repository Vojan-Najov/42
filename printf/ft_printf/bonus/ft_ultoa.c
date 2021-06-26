/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 22:57:25 by ccartman          #+#    #+#             */
/*   Updated: 2021/06/21 21:13:47 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static const char	g_dgts[] = {'0', '1', '2', '3', '4', '5', \
								'6', '7', '8', '9', 'a', 'b', \
								'c', 'd', 'e', 'f'};

static unsigned int	ft_count_digits(unsigned long n, unsigned int base);

char	*ft_ultoa_base(unsigned long n, unsigned int base)
{
	unsigned int	size;
	unsigned int	rem;
	char			*str;

	size = ft_count_digits(n, base);
	str = (char *) malloc(sizeof(*str) * (size + 1));
	if (!str)
		return (NULL);
	str[size] = '\0';
	if (n == 0)
		str[0] = g_dgts[0];
	while (n)
	{
		rem = n % base;
		str[--size] = g_dgts[rem];
		n /= base;
	}
	return (str);
}

static unsigned int	ft_count_digits(unsigned long n, unsigned int base)
{
	unsigned int	count;

	count = 0;
	if (n == 0)
		++count;
	while (n)
	{
		++count;
		n /= base;
	}
	return (count);
}
