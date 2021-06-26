/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 19:49:46 by ccartman          #+#    #+#             */
/*   Updated: 2021/06/26 15:23:42 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	ft_handle_wchar(t_fws *fws, wchar_t n);

static void	ft_handle_char(t_fws *fws, char c);

char	*ft_handle_c(t_fws *fws, const char *fmt, va_list *ap)
{
	char	c;
	wchar_t	n;

	if (fws->size == L_SIZE)
	{
		n = (wchar_t) va_arg(*ap, wint_t);
		ft_handle_wchar(fws, n);
	}
	else
	{
		c = (unsigned char) va_arg(*ap, int);
		ft_handle_char(fws, c);
	}
	return ((char *) fmt);
}

static void	ft_handle_char(t_fws *fws, char c)
{
	int		k;
	char	*sp;

	k = fws->width - 1;
	if (fws->zero && !fws->dash)
		sp = "0";
	else
		sp = " ";
	if (fws->dash)
	{
		buf_add(&c, 1);
		while (k-- > 0)
			buf_add(sp, 1);
	}
	else
	{
		while (k-- > 0)
			buf_add(sp, 1);
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
