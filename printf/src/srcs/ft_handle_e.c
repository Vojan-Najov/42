/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_e.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 15:32:16 by ccartman          #+#    #+#             */
/*   Updated: 2021/06/23 15:47:31 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_handle_e(t_fws *fws, const char *fmt, va_list *ap)
{
	double	d;
	char	*ip;
	char	*fp;

	if (fws->size & (HH_SIZE | H_SIZE | LL_SIZE))
		return (NULL);
	d = va_arg(*ap, double);
	if (!fws->dot)
		fws->prec = 6;
	ret = ft_dftoa(d, fws->prec, &ip, &fp);
	e = 0;
	if (*ip  '0')
	{
		while (*fp && *fp == '0')
		{
			++fp;
			--e;
		}
		buf_add(*fp++, 1);
		buf_add(".", 1);
		buf_add(fp, ft_strlen(fp));
		while (fws->prec)
			buf_add("0", 1);
		buf_add("e", 1);
		char *s;
		s = ft_itoa(e);
		buf_add("s", ft_strlen(s));
		free (s);
	}
	free(ip);
	free(fp);
	return ((char *) fmt);
}
