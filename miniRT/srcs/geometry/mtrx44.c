/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtrx44.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 12:30:53 by ccartman          #+#    #+#             */
/*   Updated: 2022/03/09 13:13:22 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "geometry.h"

t_mtrx44	mtrx44(double *m0, double *m1, double *m2, double *m3)
{
	t_mtrx44	mtrx;
	int			i;
	int			k;

	mtrx = (t_mtrx44) malloc(sizeof(double) * 16);
	if (!mtrx)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	k = -1;
	i = -1;
	while (++i < 4)
		mtrx[++k] = m0[i];
	i = -1;
	while (++i < 4)
		mtrx[++k] = m1[i];
	i = -1;
	while (++i < 4)
		mtrx[++k] = m2[i];
	i = -1;
	while (++i < 4)
		mtrx[++k] = m3[i];
	return (mtrx);
}

t_mtrx44	mtrx44_mult(t_mtrx44 a, t_mtrx44 b)
{
	t_mtrx44	c;
	int			i;
	int			j;

	c = (t_mtrx44) malloc(sizeof(double) * 16);
	if (!c)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			c[i * 4 + j] = a[i * 4 + 0] * b[0 * 4 + j] + \
							a[i * 4 + 1] * b[1 * 4 + j] + \
							a[i * 4 + 2] * b[2 * 4 + j] + \
							a[i * 4 + 3] * b[3 * 4 + j];
		}
	}
	return (c);
}

void	mtrx44_mult_by(t_mtrx44 *a, t_mtrx44 b)
{
	t_mtrx44	tmp;
	t_mtrx44	c;

	c = mtrx44_mult(*a, b);
	tmp = *a;
	*a = c;
	free(tmp);
}

t_mtrx44	mtrx44_transpose(t_mtrx44 m)
{
	t_mtrx44	t;
	int			i;
	int			j;

	t = (t_mtrx44) malloc(sizeof(double) * 16);
	if (!t)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			t[i * 4 + j] = m[j * 4 + i];
	}
	return (t);
}

void	mtrx44_transpose_self(t_mtrx44 m)
{
	int		i;
	int		j;
	double	tmp;

	i = 0;
	while (i < 4)
	{
		j = i + 1;
		while (j < 4)
		{
			tmp = m[i * 4 + j];
			m[i * 4 + j] = m[j * 4 + i];
			m[j * 4 + i] = tmp;
			++j;
		}
		++i;
	}
}
