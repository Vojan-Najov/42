/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_proc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 18:07:48 by ccartman          #+#    #+#             */
/*   Updated: 2021/06/16 14:27:48 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_handle_perc(t_fws *fws, const char *fmt)
{
	int	k;

	k = fws->width - 1;
	if (fws->dash)
	{
		buf_add("%", 1);
		while (k-- > 0)
			buf_add(" ", 1);
	}
	else if (fws->zero)
	{
		while (k-- > 0)
			buf_add("0", 1);
		buf_add("%", 1);
	}
	else
	{
		while (k-- > 0)
			buf_add(" ", 1);
		buf_add("%", 1);
	}
	return ((char *) fmt);
}
