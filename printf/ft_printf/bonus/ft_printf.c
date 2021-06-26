/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 17:41:37 by ccartman          #+#    #+#             */
/*   Updated: 2021/06/26 15:46:43 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static char	*buf_add_fmt(const char *fmt, va_list *ap);

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;

	buf_init();
	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt != '%')
			buf_add(fmt, 1);
		else
		{
			fmt = buf_add_fmt(++fmt, &ap);
			if (!fmt)
				return (buf_output(FTP_ERROR));
		}
		++fmt;
	}
	va_end(ap);
	return (buf_output(FTP_OK));
}

static char	*buf_add_fmt(const char *fmt, va_list *ap)
{
	t_fws	*fws;

	fws = (t_fws *) malloc(sizeof(*fws));
	if (!fws)
		return (NULL);
	fmt = ft_parse(fws, fmt, ap);
	if (!fmt)
		return (NULL);
	fmt = ft_handle_fmt(fws, fmt, ap);
	free(fws);
	return ((char *) fmt);
}
