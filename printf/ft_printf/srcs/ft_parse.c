/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 18:24:38 by ccartman          #+#    #+#             */
/*   Updated: 2021/06/26 15:43:21 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static char	*ft_parse_flags(t_fws *fws, const char *fmt);

static char	*ft_parse_before_dot(t_fws *fws, const char *fmt, va_list *ap);

static char	*ft_parse_after_dot(t_fws *fws, const char *fmt, va_list *ap);

static char	*ft_parse_type_size(t_fws *fws, const char *fmt);

char	*ft_parse(t_fws *fws, const char *fmt, va_list *ap)
{
	fws->width = 0;
	fws->prec = 0;
	fws->zero = 0;
	fws->dot = 0;
	fws->dash = 0;
	fws->hash = 0;
	fws->space = 0;
	fws->plus = 0;
	fws->size = 0;
	fmt = ft_parse_before_dot(fws, fmt, ap);
	if (fws->width < 0)
	{
		fws->width = -fws->width;
		fws->dash = F_DASH;
	}
	if (*fmt == '.')
		fmt = ft_parse_after_dot(fws, ++fmt, ap);
	fmt = ft_parse_type_size(fws, fmt);
	if (!ft_is_conversion_type(*fmt))
	{
		free(fws);
		return (NULL);
	}
	return ((char *) fmt);
}

static char	*ft_parse_before_dot(t_fws *fws, const char *fmt, va_list *ap)
{
	fmt = ft_parse_flags(fws, fmt);
	if (*fmt == '*')
	{
		fws->width = va_arg(*ap, int);
		++fmt;
	}
	else
	{
		while (ft_isdigit(*fmt))
		{
			fws->width *= 10;
			fws->width += *fmt - '0';
			++fmt;
		}
	}
	return ((char *) fmt);
}

static char	*ft_parse_flags(t_fws *fws, const char *fmt)
{
	while (!(*fmt == '.' || ft_is_conversion_type(*fmt)))
	{
		if (*fmt == '-')
			fws->dash = (unsigned char) F_DASH;
		else if (*fmt == '0')
			fws->zero = (unsigned char) F_ZERO;
		else if (*fmt == '+')
			fws->plus = (unsigned char) F_PLUS;
		else if (*fmt == ' ')
			fws->space = (unsigned char) F_SPACE;
		else if (*fmt == '#')
			fws->hash = (unsigned char) F_HASH;
		else
			return ((char *) fmt);
		++fmt;
	}
	return ((char *) fmt);
}

static char	*ft_parse_after_dot(t_fws *fws, const char *fmt, va_list *ap)
{
	fws->dot = F_DOT;
	if (*fmt == '-')
		return (NULL);
	else if (*fmt == '*')
	{
		fws->prec = va_arg(*ap, int);
		if (fws->prec < 0)
		{
			fws->dot = 0;
			fws->prec = 0;
		}
		++fmt;
	}
	else
	{
		while (ft_isdigit(*fmt))
		{
			fws->prec *= 10;
			fws->prec += *fmt - '0';
			++fmt;
		}
	}
	return ((char *) fmt);
}

static char	*ft_parse_type_size(t_fws *fws, const char *fmt)
{
	if (*fmt == 'h')
	{
		++fmt;
		if (*fmt == 'h')
		{
			fws->size = HH_SIZE;
			++fmt;
		}
		else
			fws->size = H_SIZE;
	}
	else if (*fmt == 'l')
	{
		++fmt;
		if (*fmt == 'l')
		{
			fws->size = LL_SIZE;
			++fmt;
		}
		else
			fws->size = L_SIZE;
	}
	return ((char *) fmt);
}
