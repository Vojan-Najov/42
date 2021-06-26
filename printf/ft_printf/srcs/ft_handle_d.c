/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 21:22:47 by ccartman          #+#    #+#             */
/*   Updated: 2021/06/26 15:31:04 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	ft_handle_d_total(t_fws *fws, char *s, long long n);

static void	ft_handle_d_with_dash(t_fws *fws, char *s, long long n);

static void	ft_handle_d_without_dash(t_fws *fws, char *s, long long n, \
									size_t len);

char	*ft_handle_d(t_fws *fws, const char *fmt, va_list *ap)
{
	char			*s;
	long long		n;

	if (fws->size == HH_SIZE)
		n = (char) va_arg(*ap, int);
	else if (fws->size == H_SIZE)
		n = (short) va_arg(*ap, int);
	else if (fws->size == L_SIZE)
		n = (long) va_arg(*ap, long);
	else if (fws->size == LL_SIZE)
		n = va_arg(*ap, long long);
	else
		n = (int) va_arg(*ap, int);
	s = ft_lltoa(n);
	if (!s)
		return (NULL);
	ft_handle_d_total(fws, s, n);
	free(s);
	return ((char *) fmt);
}

static void	ft_handle_d_total(t_fws *fws, char *s, long long n)
{
	size_t	len;

	len = ft_strlen(s);
	if (fws->dash)
		ft_handle_d_with_dash(fws, s, n);
	else
		ft_handle_d_without_dash(fws, s, n, len);
}

static void	ft_handle_d_with_dash(t_fws *fws, char *s, long long n)
{
	int		k;
	size_t	len;

	if (n < 0)
		buf_add(s++, 1);
	len = ft_strlen(s);
	if (fws->plus && n >= 0)
		buf_add("+", 1);
	else if (fws->space && n >= 0)
		buf_add(" ", 1);
	k = fws->prec - len;
	if (fws->dot)
		while (k-- > 0)
			buf_add("0", 1);
	if (!fws->dot || fws->prec || n)
		buf_add(s, len);
	k = fws->width - ft_max(fws->prec, len);
	if ((fws->plus || fws->space || n < 0))
		--k;
	if (fws->dot && !fws->prec && !n)
		++k;
	while (k-- > 0)
		buf_add(" ", 1);
}

static void	ft_handle_d_without_dash(t_fws *fws, char *s, long long n, \
									size_t len)
{
	int	k;

	if (n < 0 || (fws->dot && !fws->prec && !n))
		--len;
	k = fws->width - ft_max(fws->prec, len);
	if (fws->space || fws->plus || n < 0)
		--k;
	if (!fws->zero || fws->dot)
		while (k-- > 0)
			buf_add(" ", 1);
	if (fws->plus && n >= 0)
		buf_add("+", 1);
	else if (fws->space && n >= 0)
		buf_add(" ", 1);
	if (n < 0)
		buf_add(s++, 1);
	if (fws->zero && !fws->dot)
		while (k-- > 0)
			buf_add("0", 1);
	k = fws->prec - len;
	if (fws->dot)
		while (k-- > 0)
			buf_add("0", 1);
	if (!fws->dot || fws->prec || n)
		buf_add(s, len);
}
