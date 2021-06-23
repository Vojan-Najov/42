/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 13:09:13 by ccartman          #+#    #+#             */
/*   Updated: 2021/06/14 13:35:48 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	ft_handle_p_with_dash(t_fws *fws, char *s);

static void	ft_handle_p_without_dash(t_fws *fws, char *s);

char	*ft_handle_p(t_fws *fws, const char *fmt, va_list *ap)
{
	char			*s;
	unsigned long	n;

	if ((fws->zero | fws->hash | fws->plus | fws->space | fws->size) || \
		(fws->dot && fws->prec))
		return (NULL);
	n = va_arg(*ap, unsigned long);
	s = ft_ultoa_base(n, 16);
	if (!s)
		return (NULL);
	if (fws->dash)
		ft_handle_p_with_dash(fws, s);
	else
		ft_handle_p_without_dash(fws, s);
	free(s);
	return ((char *) fmt);
}

static void	ft_handle_p_with_dash(t_fws *fws, char *s)
{
	int	k;

	buf_add("0x", 2);
	buf_add(s, ft_strlen(s));
	k = fws->width - ft_strlen(s) - 2;
	while (k-- > 0)
		buf_add(" ", 1);
}

static void	ft_handle_p_without_dash(t_fws *fws, char *s)
{
	int	k;

	k = fws->width - ft_strlen(s) - 2;
	while (k-- > 0)
		buf_add(" ", 1);
	buf_add("0x", 2);
	buf_add(s, ft_strlen(s));
}