/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 19:42:51 by ccartman          #+#    #+#             */
/*   Updated: 2021/06/11 23:05:34 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	ft_p_whith_dash_handle(t_fws *fws, char *s);

static void	ft_p_whithout_dash_handle(t_fws *fws, char *s);

char	*ft_p_handle(t_fws *fws, const char *fmt, va_list *ap)
{
	char			*s;
	unsigned long	n;

	n = va_arg(*ap, unsigned long);
	s = ft_ultoa_base(n, 16);
	if (!s)
		return (NULL);
	if (fws->zero || fws->dot)
		return (NULL);
	if (fws->dash)
		ft_p_whith_dash_handle(fws, s);
	else
		ft_p_whithout_dash_handle(fws, s);
	free(s);
	return ((char *) fmt);
}

static void	ft_p_whith_dash_handle(t_fws *fws, char *s)
{
	int	k;

	buf_add("0x", 2);
	buf_add(s, ft_strlen(s));
	k = fws->width - ft_strlen(s) - 2;
	while (k-- > 0)
		buf_add(" ", 1);
}

static void	ft_p_whithout_dash_handle(t_fws *fws, char *s)
{
	int	k;

	k = fws->width - ft_strlen(s) - 2;
	while (k-- > 0)
		buf_add(" ", 1);
	buf_add("0x", 2);
	buf_add(s, ft_strlen(s));
}
