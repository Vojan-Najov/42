/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_f_part2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 19:00:14 by ccartman          #+#    #+#             */
/*   Updated: 2021/06/26 15:34:38 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	ft_add_space_or_zero(t_fws *fws, char *ip);

void	ft_handle_f_without_dash(t_fws *fws, char *ip, char *fp)
{
	fws->width -= ft_strlen(ip);
	if ((*ip != '-') && (fws->plus || fws->space))
		--fws->width;
	if (fws->prec || fws->hash)
		--fws->width;
	fws->width -= fws->prec;
	ft_add_space_or_zero(fws, ip);
	if (*ip == '-')
		++ip;
	buf_add(ip, ft_strlen(ip));
	if (fws->prec || fws->hash)
		buf_add(".", 1);
	buf_add(fp, ft_strlen(fp));
	fws->prec -= ft_strlen(fp);
	while (fws->prec-- > 0)
		buf_add("0", 1);
}

static void	ft_add_space_or_zero(t_fws *fws, char *ip)
{
	if (fws->zero)
	{
		if (*ip == '-')
			buf_add(ip++, 1);
		else if (fws->plus)
			buf_add("+", 1);
		else if (fws->space)
			buf_add(" ", 1);
		while (fws->width-- > 0)
			buf_add("0", 1);
	}
	else
	{
		while (fws->width-- > 0)
			buf_add(" ", 1);
		if (*ip == '-')
			buf_add(ip++, 1);
		else if (fws->plus)
			buf_add("+", 1);
		else if (fws->space)
			buf_add(" ", 1);
	}
}
