/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 19:49:46 by ccartman          #+#    #+#             */
/*   Updated: 2021/06/17 22:00:25 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	ft_handle_wchar(t_fws *fws, wchar_t n);

static int	ft_count_bytes(wchar_t n);

static void	ft_encode_utf8(wchar_t n);

static void	ft_handle_char(t_fws *fws, char c);

char	*ft_handle_c(t_fws *fws, const char *fmt, va_list *ap)
{
	char	c;
	wchar_t	n;

	if ((fws->zero | fws->hash | fws->plus | fws->space) || \
	(fws->dot && fws->prec) || \
	(fws->size & H_SIZE || fws->size & HH_SIZE || fws->size & LL_SIZE))
		return (NULL);
	if (fws->size == L_SIZE)
	{
		n = (wchar_t) va_arg(*ap, wint_t);
		ft_handle_wchar(fws, n);
	}
	else if (!fws->size)
	{
		c = (unsigned char) va_arg(*ap, int);
		ft_handle_char(fws, c);
	}
	return ((char *) fmt);
}

static void	ft_handle_char(t_fws *fws, char c)
{
	int	k;

	k = fws->width - 1;
	if (fws->dash)
	{
		buf_add(&c, 1);
		while (k-- > 0)
			buf_add(" ", 1);
	}
	else
	{
		while (k-- > 0)
			buf_add(" ", 1);
		buf_add(&c, 1);
	}
}

static void	ft_handle_wchar(t_fws *fws, wchar_t n)
{
	int	k;

	k = fws->width - 1;
	if (fws->dash)
	{
		ft_encode_utf8(n);
		while (k-- > 0)
			buf_add(" ", 1);
	}
	else
	{
		while (k-- > 0)
			buf_add(" ", 1);
		ft_encode_utf8(n);
	}
}

static void	ft_encode_utf8(wchar_t n)
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
