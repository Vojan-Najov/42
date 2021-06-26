/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_encode_utf8.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 13:44:44 by ccartman          #+#    #+#             */
/*   Updated: 2021/06/26 15:34:55 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	ft_count_bytes(int n);

void	ft_encode_utf8(int n)
{
	int		k;
	char	code[4];

	k = ft_count_bytes(n);
	if (k == 1)
		code[0] = 0b00000000 | n;
	else if (k == 2)
	{
		code[1] = 0b10000000 | (n & 0b00111111);
		code[0] = 0b11000000 | ((n >> 6) & 0b00011111);
	}
	else if (k == 3)
	{
		code[2] = 0b10000000 | (n & 0b00111111);
		code[1] = 0b10000000 | ((n >> 6) & 0b00111111);
		code[0] = 0b11100000 | ((n >> 12) & 0b00001111);
	}
	else if (k == 4)
	{
		code[3] = 0b10000000 | (n & 0b00111111);
		code[2] = 0b10000000 | ((n >> 6) & 0b00111111);
		code[1] = 0b10000000 | ((n >> 12) & 0b00111111);
		code[0] = 0b11110000 | ((n >> 18) & 0b00000111);
	}
	buf_add(code, k);
}

static int	ft_count_bytes(int n)
{
	int	k;

	if (0x00 <= n && n <= 0x7F)
		k = 1;
	else if (0x080 <= n && n <= 0x7FF)
		k = 2;
	else if (0x0800 <= n && n <= 0xFFFF)
		k = 3;
	else if (0x010000 <= n && n <= 0x10FFFF)
		k = 4;
	else
		k = 0;
	return (k);
}
