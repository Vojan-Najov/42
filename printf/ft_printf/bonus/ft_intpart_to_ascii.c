/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intpart_to_ascii.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 12:15:14 by ccartman          #+#    #+#             */
/*   Updated: 2021/06/26 12:29:06 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static char	*ft_bigint_to_ascii(int exp, unsigned long mant);

static char	*ft_bitoa(unsigned long *bi);

static void	ft_bi_multi_by_int(unsigned long *bi, unsigned long n);

static char	*ft_bidtoa(unsigned long bid);

char	*ft_intpart_to_ascii(int exp, unsigned long mant)
{
	mant |= IMPLICIT_UNIT;
	exp -= EXP_OFFSET;
	if (exp < 0)
		return (ft_strdup("0"));
	else if (exp <= MANT_SIZE)
	{
		mant >>= (MANT_SIZE - exp);
		return (ft_ultoa_base(mant, 10));
	}
	else if (exp < (int)(sizeof(long) * 8))
	{
		mant <<= (exp - MANT_SIZE);
		return (ft_ultoa_base(mant, 10));
	}
	else
		return (ft_bigint_to_ascii(exp - MANT_SIZE, mant));
}

static char	*ft_bigint_to_ascii(int exp, unsigned long mant)
{
	unsigned long	bi[36];
	int				i;
	char			*s;

	bi[0] = mant % BI_BASE;
	bi[1] = mant / BI_BASE;
	i = 1;
	while (++i < BI_SIZE)
		bi[i] = 0;
	while (exp >= 20)
	{
		ft_bi_multi_by_int(bi, ft_degree_of_two(20));
		exp -= 20;
	}
	if (exp)
		ft_bi_multi_by_int(bi, ft_degree_of_two(exp));
	s = ft_bitoa(bi);
	return (s);
}

static char	*ft_bitoa(unsigned long *bi)
{
	unsigned long	*ptr;
	char			*s;
	char			*tmp1;
	char			*tmp2;

	ptr = bi + BI_SIZE;
	tmp1 = NULL;
	tmp2 = NULL;
	while (*--ptr == 0)
		;
	s = ft_ultoa_base(*ptr, 10);
	if (!s)
		return (NULL);
	while (--ptr >= bi)
	{
		tmp1 = s;
		tmp2 = ft_bidtoa(*ptr);
		if (tmp2 && tmp1)
			s = ft_strjoin(tmp1, tmp2);
		free(tmp1);
		free(tmp2);
		if (!tmp2 || !s)
			return (NULL);
	}
	return (s);
}

static char	*ft_bidtoa(unsigned long bid)
{
	char	*s;
	int		i;

	s = (char *) malloc(sizeof(char) * (BI_DIGIT + 1));
	if (!s)
		return (NULL);
	i = BI_DIGIT;
	while (--i >= 0)
	{
		s[i] = (bid % 10) + '0';
		bid /= 10;
	}
	return (s);
}

static void	ft_bi_multi_by_int(unsigned long *bi, unsigned long n)
{
	int				i;
	unsigned long	carry;

	i = 0;
	carry = 0;
	while (i < BI_SIZE)
	{
		bi[i] *= n;
		bi[i] += carry;
		carry = bi[i] / BI_BASE;
		bi[i] %= BI_BASE;
		if (bi[i] == 0 && !carry)
			break ;
		++i;
	}
}
