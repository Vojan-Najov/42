/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 18:30:59 by ccartman          #+#    #+#             */
/*   Updated: 2021/06/12 20:34:48 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_handle_s(t_fws *fws, const char *fmt, va_list *ap)
{
	char	*s;
	int		len;

	if (fws->zero | fws->hash | fws->plus | fws->space | fws->size)
		return (NULL);
	s = va_arg(*ap, char *);
	if (!s)
		s = "(null)";
	len = ft_strlen(s);
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
