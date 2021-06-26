/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_factpart_to_ascii.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 16:14:44 by ccartman          #+#    #+#             */
/*   Updated: 2021/06/26 12:00:55 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static char	*ft_fill_array_by_bits(int exp, unsigned long mant);

static void	ft_fill_array_by_factorial_digits(char *a, int size);

static int	ft_fptoa(char *a, int size, int prec);

char	*ft_factpart_to_ascii(int exp, unsigned long mant, \
								int prec, int *carry)
{
	char	*a;

	mant |= IMPLICIT_UNIT;
	exp -= EXP_OFFSET;
	if (exp >= MANT_SIZE)
		return (ft_strdup(""));
	else
	{
		a = ft_fill_array_by_bits(exp, mant);
		if (!a)
			return (NULL);
		ft_fill_array_by_factorial_digits(a, MANT_SIZE - exp);
		*carry = ft_fptoa(a, 52 - exp, prec);
		return (a);
	}
}

static char	*ft_fill_array_by_bits(int exp, unsigned long mant)
{
	char	*a;
	int		k;

	if (-1 <= exp && exp <= MANT_SIZE)
	{
		mant <<= MANT_REM + exp;
		mant >>= MANT_REM + exp;
	}
	k = MANT_SIZE - exp;
	a = malloc(sizeof(char) * (k + 1));
	if (!a)
		return (NULL);
	a[k] = '\0';
	while (--k >= 0)
	{
		a[k] = mant & 0x1;
		mant >>= 1;
	}
	return (a);
}

static void	ft_fill_array_by_factorial_digits(char *a, int size)
{
	int		i;
	int		j;
	char	carry;

	i = size + 1;
	while (--i >= 0)
	{
		j = size + 1;
		while (--j >= i)
			a[j] *= 5;
		j = size + 1;
		while (--j > 0)
		{
			carry = a[j] / 10;
			a[j] %= 10;
			a[j - 1] += carry;
		}
	}
}

static int	ft_fptoa(char *a, int size, int prec)
{
	char	carry;
	int		i;

	carry = 0;
	if (prec < size)
	{
		carry = (a[prec] / 5);
		i = prec;
		while (--i >= 0)
		{
			a[i] += carry;
			carry = a[i] / 10;
			a[i] %= 10;
		}
	}
	i = -1;
	while (++i < size)
		a[i] += '0';
	if (prec < size)
		a[prec] = '\0';
	if (carry)
		a[0] = '\0';
	return (carry);
}
