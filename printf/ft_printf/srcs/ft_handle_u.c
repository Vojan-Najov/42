/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 13:23:11 by ccartman          #+#    #+#             */
/*   Updated: 2021/06/26 15:23:53 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	ft_handle_u_total(t_fws *fws, char *s, unsigned long long n);

static void	ft_handle_u_with_dot(t_fws *fws, char *s);

static void	ft_handle_u_without_dot(t_fws *fws, char *s);

char	*ft_handle_u(t_fws *fws, const char *fmt, va_list *ap)
{
	char					*s;
	unsigned long long		n;

	if (fws->size == H_SIZE)
		n = (unsigned short) va_arg(*ap, unsigned int);
	else if (fws->size == HH_SIZE)
		n = (unsigned char) va_arg(*ap, unsigned int);
	else if (fws->size == L_SIZE)
		n = (unsigned long) va_arg(*ap, unsigned long);
	else if (fws->size == LL_SIZE)
		n = va_arg(*ap, unsigned long long);
	else
		n = (unsigned int) va_arg(*ap, unsigned int);
	s = ft_ultoa_base(n, 10);
	if (!s)
		return (NULL);
	ft_handle_u_total(fws, s, n);
	free(s);
	return ((char *) fmt);
}

static void	ft_handle_u_total(t_fws *fws, char *s, unsigned long long n)
{
	int	k;

	if (fws->dot && !fws->prec && !n)
	{
		k = fws->width;
		while (k-- > 0)
			buf_add(" ", 1);
	}
	else if (fws->dot)
		ft_handle_u_with_dot(fws, s);
	else
		ft_handle_u_without_dot(fws, s);
}

static void	ft_handle_u_with_dot(t_fws *fws, char *s)
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

static void	ft_handle_u_without_dot(t_fws *fws, char *s)
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
