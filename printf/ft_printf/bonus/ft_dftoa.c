/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dftoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 11:50:04 by ccartman          #+#    #+#             */
/*   Updated: 2021/06/26 12:26:49 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void		ft_parse_float_number(double d, int *sign, int *exp, \
											unsigned long *mant);

static char		*ft_infnan_to_ascii(int sign, unsigned long mant);

static double	ft_increment_d(double d, int sign, int exp, unsigned long mant);

int	ft_dftoa(double d, int prec, char **ip, char **fp)
{
	int				exp;
	int				sign;
	unsigned long	mant;
	int				carry;
	char			*tmp;

	ft_parse_float_number(d, &sign, &exp, &mant);
	if (exp == 0x7FF)
	{
		*ip = ft_infnan_to_ascii(sign, mant);
		*fp = ft_strdup("");
		return (0);
	}
	*fp = ft_factpart_to_ascii(exp, mant, prec, &carry);
	if (carry)
		d = ft_increment_d(d, sign, exp, mant);
	ft_parse_float_number(d, &sign, &exp, &mant);
	*ip = ft_intpart_to_ascii(exp, mant);
	if (sign)
	{
		tmp = *ip;
		*ip = ft_strjoin("-", tmp);
		free(tmp);
	}
	return (1);
}

static void	ft_parse_float_number(double d, int *sign, int *exp, \
											unsigned long *mant)
{
	unsigned long	*p;
	unsigned long	m;
	int				s;
	int				e;

	p = (unsigned long *) &d;
	s = *p >> SIGN_OFFSET;
	e = (*p >> MANT_SIZE) & EXP_BITS;
	m = *p & MANT_BITS;
	*sign = s;
	*exp = e;
	*mant = m;
}

static char	*ft_infnan_to_ascii(int sign, unsigned long mant)
{
	if (mant)
	{
		if (sign)
			return (ft_strdup("-nan"));
		else
			return (ft_strdup("nan"));
	}
	else
	{
		if (sign)
			return (ft_strdup("-inf"));
		else
			return (ft_strdup("inf"));
	}
}

static double	ft_increment_d(double d, int sign, int exp, unsigned long mant)
{
	unsigned long	m;
	unsigned long	f;
	int				i;

	mant |= IMPLICIT_UNIT;
	m = (mant >> (MANT_SIZE - (exp - EXP_OFFSET))) & 0x1;
	f = (mant << (MANT_REM + exp));
	i = 0;
	while (f)
	{
		if (f & 0x1)
			++i;
		f >>= 1;
	}
	if (m || i > 1)
	{
		if (sign)
			return (d - 1.);
		else
			return (d + 1.);
	}
	else
		return (d);
}
