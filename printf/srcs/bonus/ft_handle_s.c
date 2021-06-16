/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 18:30:59 by ccartman          #+#    #+#             */
/*   Updated: 2021/06/16 20:25:03 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	ft_handle_s_char(t_fws *fws, char *s);

static void	ft_handle_s_wchar(t_fws *fws, wchar_t *ws);

static int	ft_count_bytes(int n);

static void	ft_encode_utf8(int n);

char	*ft_handle_s(t_fws *fws, const char *fmt, va_list *ap)
{
	char	*s;
	wchar_t	*ws;
	if ((fws->zero | fws->hash | fws->plus | fws->space) || \
	(fws->size & (H_SIZE | HH_SIZE| LL_SIZE)))
		return (NULL);
	if (fws->size == L_SIZE)
	{
		ws = va_arg(*ap, wchar_t *);
		ft_handle_s_wchar(fws, ws);
	}
	else
	{
		s = va_arg(*ap, char *);
		ft_handle_s_char(fws, s);
	}
		return ((char *) fmt);
}

static void	ft_handle_s_char(t_fws *fws, char *s)
{
	int	len;

	if (!s)
		s = "(null)";
	len = ft_strlen(s);
	if (fws->dot && fws->prec < len)
		len = fws->prec;
	fws->width -= len;
	if (fws->dash)
	{
		buf_add(s, len);
		while (fws->width-- > 0)
			buf_add(" ", 1);
	}
	else
	{
		while (fws->width-- > 0)
			buf_add(" ", 1);
		buf_add(s, len);
	}
}

static void	ft_handle_s_wchar(t_fws *fws, wchar_t *ws)
{
	int	len;

	len = 0;
	if (!ws)
		return (ft_handle_s_char(fws, "(null)"));
	while (ws[len])
		++len;
	if (fws->dot && fws->prec < len)
		len = fws->prec;
	fws->width -= len;
	if (fws->dash)
	{
		while (len--)
			ft_encode_utf8((int) *ws++);
		while (fws->width-- > 0)
			buf_add(" ", 1);
	}
	else
	{
		while (fws->width-- > 0)
			buf_add(" ", 1);
		while (len--)
			ft_encode_utf8((int) *ws++);
	}
}

static void	ft_encode_utf8(int n)
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
