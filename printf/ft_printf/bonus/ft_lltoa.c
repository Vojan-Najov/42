/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 16:13:27 by ccartman          #+#    #+#             */
/*   Updated: 2021/06/14 23:06:17 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static size_t	ft_count_signs(long long n);

char	*ft_lltoa(long long n)
{
	size_t	size;
	char	*str;
	int		rem;

	size = ft_count_signs(n);
	str = (char *) malloc(sizeof(*str) * (size + 1));
	if (!str)
		return (NULL);
	str[size] = '\0';
	if (n < 0)
		str[0] = '-';
	else if (n == 0)
		str[0] = '0';
	while (n)
	{
		rem = n % 10;
		if (rem < 0)
			rem = -rem;
		str[--size] = '0' + rem;
		n /= 10;
	}
	return (str);
}

static size_t	ft_count_signs(long long n)
{
	size_t	count;

	count = 0;
	if (n <= 0)
		++count;
	while (n)
	{
		++count;
		n /= 10;
	}
	return (count);
}
