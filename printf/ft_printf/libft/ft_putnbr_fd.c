/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 17:59:26 by ccartman          #+#    #+#             */
/*   Updated: 2021/04/29 18:33:01 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	buf[N];
	int		i;
	int		sign;
	int		rem;

	i = N;
	sign = 0;
	if (!n)
		buf[--i] = '0';
	if (n < 0)
		sign = 1;
	while (n)
	{
		rem = n % 10;
		if (rem < 0)
			rem = -rem;
		buf[--i] = '0' + rem;
		n /= 10;
	}
	if (sign)
		buf[--i] = '-';
	write(fd, buf + i, N - i);
	return ;
}
