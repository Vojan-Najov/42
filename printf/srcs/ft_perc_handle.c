/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 18:30:59 by ccartman          #+#    #+#             */
/*   Updated: 2021/06/11 16:12:45 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_perc_handle(t_fws *fws, const char *fmt)
{
	int	k;

	if (fws->dash)
	{
		buf_add("%", 1);
		k = fws->width - 1;
		while (k-- > 0)
			buf_add(" ", 1);
	}
	else if (!fws->zero)
	{
		k = fws->width - 1;
		while (k-- > 0)
			buf_add(" ", 1);
		buf_add("%", 1);
	}
	else if (fws->zero)
	{
		k = fws->width - 1;
		while (k-- > 0)
			buf_add("0", 1);
		buf_add("%", 1);
	}
	return ((char *) fmt);
}

char	*ft_c_handle(t_fws *fws, const char *fmt, va_list *ap)
{
	char	c;

	c = (unsigned char) va_arg(*ap, int);
	if (fws->zero || fws->dot)
		return (NULL);
	if (!fws->dash)
	{
		while(--fws->width > 0)
			buf_add(" ", 1);
		buf_add(&c, 1);
	}
	else
	{
		buf_add(&c, 1);
		while (--fws->width > 0)
			buf_add(" ", 1);
	}
	return ((char *) fmt);
}

char	*ft_s_handle(t_fws *fws, const char *fmt, va_list *ap)
{
	char	*s;
	int		len;

	s = va_arg(*ap, char *);
	if (!s)
		s = "(null)";
	len = ft_strlen(s);
	if (fws->zero)
		return (NULL);
	if (fws->dot && fws->prec < len)
		len = fws->prec;
	if (fws->dash)
	{
		buf_add(s, len);
		fws->width -= len;
		while (fws->width-- > 0)
			buf_add(" ", 1);
	}
	else
	{
		fws->width -= len;
		while (fws->width-- > 0)
			buf_add(" ", 1);
		buf_add(s, len);
	}
	return ((char *) fmt);
}

int	ft_max(int a, int b)
{
	if (a < b)
		return (b);
	else
		return (a);
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	else 
		return (b);
}


char	*ft_d_handle(t_fws *fws, const char *fmt, va_list *ap)
{
	char	*s;
	char	*str;
	int		n;
	int		k;
	int		len;

	n = va_arg(*ap, int);
	str = ft_itoa(n);
	s = str;
	if (!s)
		return (NULL);
	if (fws->dot && !fws->prec && !n)
	{
		k = fws->width;
		while (k-- > 0)
			buf_add(" ", 1);
		return ((char *) fmt);
	}
	len = ft_strlen(s);
	if (fws->dot)
		if (fws->dash)
		{
			if (n < 0)
				buf_add(s++, 1);
			k = fws->prec - ft_strlen(s);
			while (k-- > 0)
				buf_add("0", 1);
			buf_add(s, ft_strlen(s));
			k = fws->width - ft_max(fws->prec, ft_strlen(s));
			if (n < 0 && fws->prec > len - 1)
				--k;
			if (n < 0 && fws->prec < len)
				--k;
			while (k-- > 0)
				buf_add(" ", 1);
		}
		else
		{
			k = fws->width - ft_max(fws->prec, len);
			if (n < 0 && fws->prec > len - 1)
				--k;
			while (k-- > 0)
				buf_add(" ", 1);
			if (n < 0)
				buf_add(s++, 1);
			k = fws->prec - ft_strlen(s);
			while (k-- > 0)
				buf_add("0", 1);
			buf_add(s, ft_strlen(s));
		}
	else if (fws->dash)
	{
		k = fws->width - ft_strlen(s);
		buf_add(s, ft_strlen(s));
		while (k-- > 0)
			buf_add(" ", 1);
	}
	else if (fws->zero)
	{
		if (n < 0)
			buf_add(s++, 1);
		k = fws->width - len;
		while (k-- > 0)
			buf_add("0", 1);
		buf_add(s, ft_strlen(s));
	}
	else
	{
		k = fws->width - ft_strlen(s);
		while (k-- > 0)
			buf_add(" ", 1);
		buf_add(s, ft_strlen(s));
	}
	free(str);
	return ((char *) fmt);
}

char	*ft_u_handle(t_fws *fws, const char *fmt, va_list *ap)
{
	char	*s;
	int		n;
	int		k;

	n = va_arg(*ap, int);
	s = ft_utoa_base(n, 10);
	if (!s)
		return (NULL);
	if (fws->dot && !fws->prec && !n)
	{
		k = fws->width;
		while (k-- > 0)
			buf_add(" ", 1);
		return ((char *) fmt);
	}
	if (fws->dot)
		if (fws->dash)
		{
			k = fws->prec - ft_strlen(s);
			while (k-- > 0)
				buf_add("0", 1);
			buf_add(s, ft_strlen(s));
			k = fws->width - ft_max(fws->prec, ft_strlen(s));
			while (k-- > 0)
				buf_add(" ", 1);
		}
		else
		{
			k = fws->width - ft_max(fws->prec, ft_strlen(s));;
			while (k-- > 0)
				buf_add(" ", 1);
			k = fws->prec - ft_strlen(s);
			while (k-- > 0)
				buf_add("0", 1);
			buf_add(s, ft_strlen(s));
		}
	else if (fws->dash)
	{
		k = fws->width - ft_strlen(s);
		buf_add(s, ft_strlen(s));
		while (k-- > 0)
			buf_add(" ", 1);
	}
	else if (fws->zero)
	{
		k = fws->width - ft_strlen(s);
		while (k-- > 0)
			buf_add("0", 1);
		buf_add(s, ft_strlen(s));
	}
	else
	{
		k = fws->width - ft_strlen(s);
		while (k-- > 0)
			buf_add(" ", 1);
		buf_add(s, ft_strlen(s));
	}
	return ((char *) fmt);
}

char	*ft_x_handle(t_fws *fws, const char *fmt, va_list *ap)
{
	char	*s;
	int		n;
	int		k;

	n = va_arg(*ap, int);
	s = ft_utoa_base(n, 16);
	if (!s)
		return (NULL);
	if (fws->dot && !fws->prec && !n)
	{
		k = fws->width;
		while (k-- > 0)
			buf_add(" ", 1);
		return ((char *) fmt);
	}
	if (fws->dot)
		if (fws->dash)
		{
			k = fws->prec - ft_strlen(s);
			while (k-- > 0)
				buf_add("0", 1);
			buf_add(s, ft_strlen(s));
			k = fws->width - ft_max(fws->prec, ft_strlen(s));
			while (k-- > 0)
				buf_add(" ", 1);
		}
		else
		{
			k = fws->width - ft_max(fws->prec, ft_strlen(s));;
			while (k-- > 0)
				buf_add(" ", 1);
			k = fws->prec - ft_strlen(s);
			while (k-- > 0)
				buf_add("0", 1);
			buf_add(s, ft_strlen(s));
		}
	else if (fws->dash)
	{
		k = fws->width - ft_strlen(s);
		buf_add(s, ft_strlen(s));
		while (k-- > 0)
			buf_add(" ", 1);
	}
	else if (fws->zero)
	{
		k = fws->width - ft_strlen(s);
		while (k-- > 0)
			buf_add("0", 1);
		buf_add(s, ft_strlen(s));
	}
	else
	{
		k = fws->width - ft_strlen(s);
		while (k-- > 0)
			buf_add(" ", 1);
		buf_add(s, ft_strlen(s));
	}
	return ((char *) fmt);
}

char	*ft_xx_handle(t_fws *fws, const char *fmt, va_list *ap)
{
	char	*s;
	char	*p;
	int		n;
	int		k;

	n = va_arg(*ap, int);
	s = ft_utoa_base(n, 16);
	if (!s)
		return (NULL);
	p = s;
	while (*p)
	{
		*p = ft_toupper(*p);
		++p;
	}
	if (fws->dot && !fws->prec && !n)
	{
		k = fws->width;
		while (k-- > 0)
			buf_add(" ", 1);
		return ((char *) fmt);
	}
	if (fws->dot)
		if (fws->dash)
		{
			k = fws->prec - ft_strlen(s);
			while (k-- > 0)
				buf_add("0", 1);
			buf_add(s, ft_strlen(s));
			k = fws->width - ft_max(fws->prec, ft_strlen(s));
			while (k-- > 0)
				buf_add(" ", 1);
		}
		else
		{
			k = fws->width - ft_max(fws->prec, ft_strlen(s));;
			while (k-- > 0)
				buf_add(" ", 1);
			k = fws->prec - ft_strlen(s);
			while (k-- > 0)
				buf_add("0", 1);
			buf_add(s, ft_strlen(s));
		}
	else if (fws->dash)
	{
		k = fws->width - ft_strlen(s);
		buf_add(s, ft_strlen(s));
		while (k-- > 0)
			buf_add(" ", 1);
	}
	else if (fws->zero)
	{
		k = fws->width - ft_strlen(s);
		while (k-- > 0)
			buf_add("0", 1);
		buf_add(s, ft_strlen(s));
	}
	else
	{
		k = fws->width - ft_strlen(s);
		while (k-- > 0)
			buf_add(" ", 1);
		buf_add(s, ft_strlen(s));
	}
	return ((char *) fmt);
}

char	*ft_p_handle(t_fws *fws, const char *fmt, va_list *ap)
{
	char			*s;
	int				k;
	unsigned long	n;
	
	n = va_arg(*ap, unsigned long);
	s = ft_ultoa_base(n, 16);
	if (!s)
		return (NULL);
	if (fws->zero || fws->dot)
		return (NULL);
	if (fws->dash)	
	{
		buf_add("0x", 2);
		buf_add(s, ft_strlen(s));
		k = fws->width - ft_strlen(s) - 2;
		while (k-- > 0)
			buf_add(" ", 1);
	}
	else
	{
		k = fws->width - ft_strlen(s) - 2;
		while (k-- > 0)
			buf_add(" ", 1);
		buf_add("0x", 2);
		buf_add(s, ft_strlen(s));
	}
	return ((char*) fmt);
}


char	*ft_fmt_handle(t_fws *fws, const char *fmt, va_list *ap)
{
	if (*fmt == '%')
		return(ft_perc_handle(fws, fmt));
	if (*fmt == 'c')
		return (ft_c_handle(fws, fmt, ap));
	else if (*fmt == 's')
		return (ft_s_handle(fws, fmt, ap));
	else if (*fmt == 'd' || *fmt == 'i')
		return (ft_d_handle(fws, fmt, ap));
	else if (*fmt == 'u')
		return (ft_u_handle(fws, fmt, ap));
	else if (*fmt == 'x')
		return (ft_x_handle(fws, fmt, ap));
	else if (*fmt == 'X')
		return (ft_xx_handle(fws, fmt, ap));
	else if (*fmt == 'p')
	return (ft_p_handle(fws, fmt, ap));
	else
		buf_add("000", 3);
	return ((char *) fmt);
}
