/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 18:24:38 by ccartman          #+#    #+#             */
/*   Updated: 2021/06/10 20:59:41 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_parse_before_dot(t_fws *fws, const char *fmt, va_list *ap)
{
	while (*fmt != '.' && !ft_is_conversion_type(*fmt))
	{
		if (*fmt == '0')
			fws->zero = 1;
		if (*fmt == '-')
			fws->dash = 1;
		if (*fmt == '*')
		{
			fws->width = va_arg(*ap, int);
			++fmt;
			break ;
		}
		if ('1' <= *fmt && *fmt <='9')
		{
			while (ft_isdigit(*fmt))
			{
				fws->width *= 10;
				fws->width += *fmt - '0';
				++fmt;
			}
			break ;
		}
		++fmt;
	}
	return ((char *) fmt);
}

char	*ft_parse_after_dot(t_fws *fws, const char *fmt, va_list *ap)
{
	fws->dot = 1;
	if (*fmt == '-')
		return (NULL);
	else if (*fmt == '*')
	{
		fws->prec = va_arg(*ap, int);
		if (fws->prec < 0)
			fws->dot = 0;
		++fmt;
	}
	else 
		while (ft_isdigit(*fmt))
		{
			fws->prec *= 10;
			fws->prec += *fmt - '0';
			++fmt;
		}
	return ((char *) fmt);
}

char	*ft_parse(t_fws *fws, const char *fmt, va_list *ap)
{
	fws->width = 0;
	fws->prec = 0;
	fws->zero = 0;
	fws->dot = 0;
	fws->dash = 0;
	fmt = ft_parse_before_dot(fws, fmt, ap);
	if (fws->width < 0)
	{
		fws->width = -fws->width;
		fws->dash = 1;
	}
	if (*fmt == '.')
		fmt = ft_parse_after_dot(fws, ++fmt, ap);
	if (!ft_is_conversion_type(*fmt))
	{
		free(fws);
		return (NULL);
	}
	//printf("z = %d dt = %d dsh = %d wid = %d prec = %d *fmt = %c\n", \
	//		   fws->zero, fws->dot, fws->dash, fws->width, fws->prec, *fmt);	
	return ((char *) fmt);
}
