/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 18:30:59 by ccartman          #+#    #+#             */
/*   Updated: 2021/06/26 16:06:18 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_handle_fmt(t_fws *fws, const char *fmt, va_list *ap)
{
	if (*fmt == '%')
		return (ft_handle_perc(fws, fmt));
	if (*fmt == 'c')
		return (ft_handle_c(fws, fmt, ap));
	else if (*fmt == 's')
		return (ft_handle_s(fws, fmt, ap));
	else if (*fmt == 'p')
		return (ft_handle_p(fws, fmt, ap));
	else if (*fmt == 'u')
		return (ft_handle_u(fws, fmt, ap));
	else if (*fmt == 'x')
		return (ft_handle_x(fws, fmt, ap));
	else if (*fmt == 'X')
		return (ft_handle_xx(fws, fmt, ap));
	else if (*fmt == 'd' || *fmt == 'i')
		return (ft_handle_d(fws, fmt, ap));
	else
		return (NULL);
}
