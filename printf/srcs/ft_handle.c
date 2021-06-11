/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 18:30:59 by ccartman          #+#    #+#             */
/*   Updated: 2021/06/11 19:25:14 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static char	*ft_perc_handle(t_fws *fws, const char *fmt);

static char	*ft_c_handle(t_fws *fws, const char *fmt, va_list *ap);

static char	*ft_s_handle(t_fws *fws, const char *fmt, va_list *ap);

char	*ft_fmt_handle(t_fws *fws, const char *fmt, va_list *ap)
{
	if (*fmt == '%')
		return (ft_perc_handle(fws, fmt));
	if (*fmt == 'c')
		return (ft_c_handle(fws, fmt, ap));
	else if (*fmt == 's')
		return (ft_s_handle(fws, fmt, ap));
	else if (*fmt == 'd' || *fmt == 'i')
		return (ft_d_handle(fws, fmt, ap));
	else if (*fmt == 'u')
		return (ft_u_handle(fws, fmt, ap));
	else if (*fmt == 'x')
		return (ft_x_handle(fws, fmt, ap));
	else if (*fmt == 'X')
		return (ft_xx_handle(fws, fmt, ap));
	else if (*fmt == 'p')
		return (ft_p_handle(fws, fmt, ap));
	return ((char *) fmt);
}

static char	*ft_perc_handle(t_fws *fws, const char *fmt)
{
	int	k;

	k = fws->width - 1;
	if (fws->dash)
	{
		buf_add("%", 1);
		while (k-- > 0)
			buf_add(" ", 1);
	}
	else if (!fws->zero)
	{
		while (k-- > 0)
			buf_add(" ", 1);
		buf_add("%", 1);
	}
	else
	{
		while (k-- > 0)
			buf_add("0", 1);
		buf_add("%", 1);
	}
	return ((char *) fmt);
}

static char	*ft_c_handle(t_fws *fws, const char *fmt, va_list *ap)
{
	char	c;
	int		k;

	c = (unsigned char) va_arg(*ap, int);
	if (fws->zero || fws->dot)
		return (NULL);
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
	return ((char *) fmt);
}

static char	*ft_s_handle(t_fws *fws, const char *fmt, va_list *ap)
{
	char	*s;
	int		len;

	s = va_arg(*ap, char *);
	if (!s)
		s = "(null)";
	len = ft_strlen(s);
	if (fws->zero)
		return (NULL);
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
	return ((char *) fmt);
}
