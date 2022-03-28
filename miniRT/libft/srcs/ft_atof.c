/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoan <jjoan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 19:32:39 by ccartman          #+#    #+#             */
/*   Updated: 2022/02/22 16:52:24 by jjoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <math.h>

// int	ft_isdigit(int c)
// {
// 	if ('0' <= c && c <= '9')
// 		return (c);
// 	else
// 		return (0);
// }

int	check_float(const char *str)
{
	if (*str == '-' || *str == '+')
		++str;
	if (!ft_isdigit(*str))
		return (0);
	while (ft_isdigit(*str))
		++str;
	if (*str == '.')
		++str;
	else if (!ft_isprint(*str))
		return (1);
	while (ft_isdigit(*str))
		++str;
	if (!ft_isprint(*str))
		return (1);
	else
		return (0);
}

double	ft_atof(const char *str)
{
	int		sign;
	int		count;
	double	d;

	d = 0;
	sign = 1;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		++str;
	while (*str && *str != '.')
	{
		d = 10 * d + (*str - '0');
		++str;
	}
	if (*str == '.')
		++str;
	count = 0;
	while (*str)
	{
		--count;
		d += (*str - '0') * pow(10.0, (double) count);
		++str;
	}
	return (sign * d);
}
