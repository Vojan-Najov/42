/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 23:02:15 by ccartman          #+#    #+#             */
/*   Updated: 2021/06/11 23:02:35 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	ft_d_with_dot_handle(t_fws *fws, char *s, int n);

static void	ft_d_with_dot_with_dash_handle(t_fws *fws, char *s, int n);

static void	ft_d_with_dot_without_dash_handle(t_fws *fws, char *s, int n);

static void	ft_d_without_dot_handle(t_fws *fws, char *s, int n, int len);

char	*ft_d_handle(t_fws *fws, const char *fmt, va_list *ap)
{
	char	*s;
	int		n;
	int		k;
	int		len;

	n = va_arg(*ap, int);
	s = ft_itoa(n);
	if (!s)
		return (NULL);
	if (fws->dot && !fws->prec && !n)
	{
		k = fws->width;
		while (k-- > 0)
			buf_add(" ", 1);
		return ((char *) fmt);
	}
	len = ft_strlen(s);
	if (fws->dot)
		ft_d_with_dot_handle(fws, s, n);
	else
		ft_d_without_dot_handle(fws, s, n, len);
	free(s);
	return ((char *) fmt);
}

static void	ft_d_with_dot_handle(t_fws *fws, char *s, int n)
{
	if (fws->dash)
		ft_d_with_dot_with_dash_handle(fws, s, n);
	else
		ft_d_with_dot_without_dash_handle(fws, s, n);
}

static void	ft_d_with_dot_with_dash_handle(t_fws *fws, char *s, int n)
{
	int	len;
	int	k;

	len = ft_strlen(s);
	if (n < 0)
		buf_add(s++, 1);
	k = fws->prec - ft_strlen(s);
	while (k-- > 0)
		buf_add("0", 1);
	buf_add(s, ft_strlen(s));
	k = fws->width - ft_max(fws->prec, ft_strlen(s));
	if (n < 0)
		--k;
	while (k-- > 0)
		buf_add(" ", 1);
}

static void	ft_d_with_dot_without_dash_handle(t_fws *fws, char *s, int n)
{
	int	k;
	int	len;

	len = ft_strlen(s);
	k = fws->width - ft_max(fws->prec, len);
	if (n < 0 && fws->prec > len - 1)
		--k;
	while (k-- > 0)
		buf_add(" ", 1);
	if (n < 0)
		buf_add(s++, 1);
	k = fws->prec - ft_strlen(s);
	while (k-- > 0)
		buf_add("0", 1);
	buf_add(s, ft_strlen(s));
}

static void	ft_d_without_dot_handle(t_fws *fws, char *s, int n, int len)
{
	int	k;

	if (fws->dash)
	{
		k = fws->width - ft_strlen(s);
		buf_add(s, ft_strlen(s));
		while (k-- > 0)
			buf_add(" ", 1);
	}
	else if (fws->zero)
	{
		if (n < 0)
			buf_add(s++, 1);
		k = fws->width - len;
		while (k-- > 0)
			buf_add("0", 1);
		buf_add(s, ft_strlen(s));
	}
	else
	{
		k = fws->width - ft_strlen(s);
		while (k-- > 0)
			buf_add(" ", 1);
		buf_add(s, ft_strlen(s));
	}
}
