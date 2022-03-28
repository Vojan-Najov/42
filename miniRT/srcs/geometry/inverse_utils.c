/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inverse_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 12:56:09 by ccartman          #+#    #+#             */
/*   Updated: 2022/03/09 12:53:08 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"

void	gauss_backward(double *b)
{
	int		i;
	int		j;
	int		k;
	double	tmp;

	k = 4;
	while (--k > 0)
	{
		i = -1;
		while (++i < k)
		{
			tmp = b[8 * i + k];
			j = k - 1;
			while (++j < 8)
				b[8 * i + j] -= (b[8 * k + j] * tmp);
		}
	}
}

void	gauss_forward_row(double *b, int row)
{
	double	tmp;
	int		i;
	int		j;

	j = row;
	tmp = b[8 * row + j];
	while (j < 8)
	{
		b[8 * row + j] /= tmp;
		++j;
	}
	i = row;
	while (++i < 4)
	{
		j = row;
		tmp = b[8 * i + j];
		while (j < 8)
		{
			b[8 * i + j] -= (b[8 * row + j] * tmp);
			++j;
		}
	}
}

void	mtrx48_swap_rows(double *b, int i, int j)
{
	double	tmp;
	int		k;

	k = 0;
	while (k < 8)
	{
		tmp = b[8 * i + k];
		b[8 * i + k] = b[8 * j + k];
		b[8 * j + k] = tmp;
		++k;
	}
}
