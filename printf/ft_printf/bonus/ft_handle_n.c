/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 20:53:18 by ccartman          #+#    #+#             */
/*   Updated: 2021/06/26 15:40:57 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_handle_n(t_fws *fws, const char *fmt, va_list *ap)
{
	if (fws->size == HH_SIZE)
		*(va_arg(*ap, char *)) = (char) buf_count();
	else if (fws->size == H_SIZE)
		*(va_arg(*ap, short *)) = (short) buf_count();
	else if (fws->size == L_SIZE)
		*(va_arg(*ap, long *)) = (long) buf_count();
	else if (fws->size == LL_SIZE)
		*(va_arg(*ap, long long *)) = (long long) buf_count();
	else
		*(va_arg(*ap, int *)) = buf_count();
	return ((char *) fmt);
}
