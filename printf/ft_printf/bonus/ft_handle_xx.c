/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_xx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 21:11:30 by ccartman          #+#    #+#             */
/*   Updated: 2021/06/26 15:29:25 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	ft_handle_xx_total(t_fws *fws, char *s, unsigned long long n);

static void	ft_handle_xx_with_dash(t_fws *fws, char *s, unsigned long long n);

static void	ft_handle_xx_without_dash(t_fws *fws, char *s, \
										unsigned long long n);

char	*ft_handle_xx(t_fws *fws, const char *fmt, va_list *ap)
{
	char					*s;
	unsigned long long		n;

	if (fws->size == HH_SIZE)
		n = (unsigned char) va_arg(*ap, unsigned int);
	else if (fws->size == H_SIZE)
		n = (unsigned short) va_arg(*ap, unsigned int);
	else if (fws->size == L_SIZE)
		n = (unsigned long) va_arg(*ap, unsigned long);
	else if (fws->size == LL_SIZE)
		n = (unsigned long) va_arg(*ap, unsigned long long);
	else
		n = (unsigned int) va_arg(*ap, unsigned int);
	s = ft_ultoa_base(n, 16);
	if (!s)
		return (NULL);
	ft_handle_xx_total(fws, s, n);
	free(s);
	return ((char *) fmt);
}

static void	ft_handle_xx_total(t_fws *fws, char *s, unsigned long long n)
{
	int		k;
	char	*ptr;

	ptr = s;
	while (*ptr)
	{
		*ptr = ft_toupper(*ptr);
		++ptr;
	}
	if (fws->dot && !fws->prec && !n)
	{
		k = fws->width;
		while (k--)
			buf_add(" ", 1);
	}
	else if (fws->dash)
		ft_handle_xx_with_dash(fws, s, n);
	else
		ft_handle_xx_without_dash(fws, s, n);
}

static void	ft_handle_xx_with_dash(t_fws *fws, char *s, unsigned long long n)
{
	int	k;
	int	p;
	int	len;

	len = ft_strlen(s);
	k = fws->width - ft_max(fws->prec, len);
	if (fws->hash && n)
	{
		buf_add("0X", 2);
		k -= 2;
	}
	if (fws->dot)
	{
		p = fws->prec - len;
		while (p-- > 0)
			buf_add("0", 1);
	}
	buf_add(s, len);
	while (k-- > 0)
		buf_add(" ", 1);
}

static void	ft_handle_xx_without_dash(t_fws *fws, char *s, unsigned long long n)
{
	int	k;
	int	len;

	len = ft_strlen(s);
	k = fws->width - ft_max(fws->prec, len);
	if (fws->hash && n)
		k -= 2;
	if (fws->zero && !fws->dot && !fws->hash)
		while (k-- > 0)
			buf_add("0", 1);
	else if (!fws->zero || fws->dot)
		while (k-- > 0)
			buf_add(" ", 1);
	if (fws->hash && n)
		buf_add("0X", 2);
	if (fws->hash && fws->zero && !fws->dot)
		while (k-- > 0)
			buf_add("0", 1);
	k = fws->prec - len;
	if (fws->dot)
		while (k-- > 0)
			buf_add("0", 1);
	buf_add(s, len);
}
