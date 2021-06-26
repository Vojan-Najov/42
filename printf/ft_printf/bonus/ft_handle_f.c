/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 11:42:06 by ccartman          #+#    #+#             */
/*   Updated: 2021/06/26 15:37:25 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	ft_handle_f_infnan(t_fws *fws, char *s, int len);

static void	ft_handle_f_infnan_without_dash(t_fws *fws, char *s, int len);

static void	ft_handle_f_with_dash(t_fws *fws, char *ip, char *fp);

static void	ft_handle_f_with_dash_fact(t_fws *fws, char *fp);

char	*ft_handle_f(t_fws *fws, const char *fmt, va_list *ap)
{
	double	d;
	char	*ip;
	char	*fp;
	int		ret;

	d = va_arg(*ap, double);
	if (!fws->dot)
		fws->prec = 6;
	ret = ft_dftoa(d, fws->prec, &ip, &fp);
	if (!ip || !fp)
		return (NULL);
	if (ret == 0)
		ft_handle_f_infnan(fws, ip, ft_strlen(ip));
	else if (fws->dash)
		ft_handle_f_with_dash(fws, ip, fp);
	else
		ft_handle_f_without_dash(fws, ip, fp);
	free(ip);
	free(fp);
	return ((char *) fmt);
}

static void	ft_handle_f_infnan(t_fws *fws, char *s, int len)
{
	if (fws->dash)
	{
		if (fws->plus && *s == 'i')
		{
			buf_add("+", 1);
			--fws->width;
		}
		else if (fws->space && *s == 'i')
		{
			buf_add(" ", 1);
			--fws->width;
		}
		buf_add(s, len);
		fws->width -= len;
		while (fws->width-- > 0)
			buf_add(" ", 1);
	}
	else
		ft_handle_f_infnan_without_dash(fws, s, len);
}

static void	ft_handle_f_infnan_without_dash(t_fws *fws, char *s, int len)
{
	if ((fws->plus || fws->space) && *s == 'i')
		--fws->width;
	fws->width -= len;
	while (fws->width-- > 0)
		buf_add(" ", 1);
	if (fws->plus && *s == 'i')
		buf_add("+", 1);
	else if (fws->space && *s == 'i')
		buf_add(" ", 1);
	buf_add(s, len);
}

static void	ft_handle_f_with_dash(t_fws *fws, char *ip, char *fp)
{
	size_t	len;

	if (*ip == '-' || fws->plus || fws->space)
		--fws->width;
	if (*ip == '-')
		buf_add(ip++, 1);
	else if (fws->plus)
		buf_add("+", 1);
	else if (fws->space)
		buf_add(" ", 1);
	len = ft_strlen(ip);
	buf_add(ip, len);
	fws->width -= len;
	ft_handle_f_with_dash_fact(fws, fp);
}

static void	ft_handle_f_with_dash_fact(t_fws *fws, char *fp)
{
	size_t	len;

	if (fws->prec || fws->hash)
	{
		buf_add(".", 1);
		fws->width--;
	}
	len = ft_strlen(fp);
	buf_add(fp, len);
	fws->width -= len;
	fws->prec -= len;
	if (fws->prec > 0)
		fws->width -= fws->prec;
	while (fws->prec-- > 0)
		buf_add("0", 1);
	while (fws->width-- > 0)
		buf_add(" ", 1);
}
