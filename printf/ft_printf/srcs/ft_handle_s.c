/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 18:30:59 by ccartman          #+#    #+#             */
/*   Updated: 2021/06/26 16:35:35 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	ft_handle_s_char(t_fws *fws, char *s);

static void	ft_handle_s_char_without_dash(t_fws *fws, char *s, int len);

char	*ft_handle_s(t_fws *fws, const char *fmt, va_list *ap)
{
	char	*s;

	s = (char *) va_arg(*ap, char *);
	ft_handle_s_char(fws, s);
	return ((char *) fmt);
}

static void	ft_handle_s_char(t_fws *fws, char *s)
{
	int	len;

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
		ft_handle_s_char_without_dash(fws, s, len);
}

static void	ft_handle_s_char_without_dash(t_fws *fws, char *s, int len)
{
	char	*c;

	if (fws->zero)
		c = "0";
	else
		c = " ";
	while (fws->width-- > 0)
		buf_add(c, 1);
	buf_add(s, len);
}
