/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 23:05:53 by ccartman          #+#    #+#             */
/*   Updated: 2021/06/11 23:06:06 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	ft_u_with_dot_handle(t_fws *fws, char *s);

static void	ft_u_without_dot_handle(t_fws *fws, char *s);

char	*ft_u_handle(t_fws *fws, const char *fmt, va_list *ap)
{
	char	*s;
	int		n;
	int		k;

	n = va_arg(*ap, int);
	s = ft_utoa_base(n, 10);
	if (!s)
		return (NULL);
	if (fws->dot && !fws->prec && !n)
	{
		k = fws->width;
		while (k-- > 0)
			buf_add(" ", 1);
		return ((char *) fmt);
	}
	if (fws->dot)
		ft_u_with_dot_handle(fws, s);
	else
		ft_u_without_dot_handle(fws, s);
	free(s);
	return ((char *) fmt);
}

static void	ft_u_with_dot_handle(t_fws *fws, char *s)
{
	int	k;
	int	len;

	len = ft_strlen(s);
	if (fws->dash)
	{
		k = fws->prec - len;
		while (k-- > 0)
			buf_add("0", 1);
		buf_add(s, len);
		k = fws->width - ft_max(fws->prec, len);
		while (k-- > 0)
			buf_add(" ", 1);
	}
	else
	{
		k = fws->width - ft_max(fws->prec, len);
		while (k-- > 0)
			buf_add(" ", 1);
		k = fws->prec - len;
		while (k-- > 0)
			buf_add("0", 1);
		buf_add(s, len);
	}
}

static void	ft_u_without_dot_handle(t_fws *fws, char *s)
{
	int	k;
	int	len;

	len = ft_strlen(s);
	k = fws->width - len;
	if (fws->dash)
	{
		buf_add(s, len);
		while (k-- > 0)
			buf_add(" ", 1);
	}
	else if (fws->zero)
	{
		while (k-- > 0)
			buf_add("0", 1);
		buf_add(s, len);
	}
	else
	{
		while (k-- > 0)
			buf_add(" ", 1);
		buf_add(s, len);
	}
}
