/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 13:06:09 by ccartman          #+#    #+#             */
/*   Updated: 2022/03/18 06:07:51 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

static double	*init_big(t_mtrx44 m);

static void		init_big_part2(double *b, t_mtrx44 m);

static t_mtrx44	return_error(double *b);

static int		set_pivot(double *b, int row);

t_mtrx44	mtrx44_inverse(t_mtrx44 m)
{
	double		*b;
	t_mtrx44	invrs;

	b = init_big(m);
	if (!set_pivot(b, 0))
		return (return_error(b));
	gauss_forward_row(b, 0);
	if (!set_pivot(b, 1))
		return (return_error(b));
	gauss_forward_row(b, 1);
	if (!set_pivot(b, 2))
		return (return_error(b));
	gauss_forward_row(b, 2);
	if (!set_pivot(b, 3))
		return (return_error(b));
	gauss_forward_row(b, 3);
	gauss_backward(b);
	invrs = mtrx44(b + 4, b + 12, b + 20, b + 28);
	free(b);
	mtrx44_round(invrs);
	return (invrs);
}

static int	set_pivot(double *b, int row)
{
	int	i;
	int	j;

	j = row;
	if (fabs(b[8 * row + j]) > g_eps)
		return (1);
	i = row + 1;
	while (i < 4)
	{
		if (fabs(b[8 * i + row]) > g_eps)
		{
			mtrx48_swap_rows(b, row, i);
			return (1);
		}
		++i;
	}
	return (0);
}

static t_mtrx44	return_error(double *b)
{
	free(b);
	return ((t_mtrx44) 0);
}

static double	*init_big(t_mtrx44 m)
{
	double	*b;

	b = (double *) malloc(sizeof(double) * 32);
	if (!b)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	b[0] = m[0];
	b[1] = m[1];
	b[2] = m[2];
	b[3] = m[3];
	b[4] = 1.;
	b[5] = 0.;
	b[6] = 0.;
	b[7] = 0.;
	init_big_part2(b, m);
	return (b);
}

static void	init_big_part2(double *b, t_mtrx44 m)
{
	b[8] = m[4];
	b[9] = m[5];
	b[10] = m[6];
	b[11] = m[7];
	b[12] = 0.;
	b[13] = 1.;
	b[14] = 0.;
	b[15] = 0.;
	b[16] = m[8];
	b[17] = m[9];
	b[18] = m[10];
	b[19] = m[11];
	b[20] = 0.;
	b[21] = 0.;
	b[22] = 1.;
	b[23] = 0.;
	b[24] = m[12];
	b[25] = m[13];
	b[26] = m[14];
	b[27] = m[15];
	b[28] = 0.;
	b[29] = 0.;
	b[30] = 0.;
	b[31] = 1.;
}
