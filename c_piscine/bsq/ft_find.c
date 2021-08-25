/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malison <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 17:58:54 by malison           #+#    #+#             */
/*   Updated: 2021/03/10 21:15:20 by malison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

unsigned int	ft_min(unsigned int a, unsigned int b, unsigned int c)
{
	unsigned int min;

	min = a;
	if (b < min)
		min = b;
	if (c < min)
		min = c;
	return (min);
}

void			ft_sq_update(t_sq *sq, unsigned int x, unsigned int y, \
				unsigned int s)
{
	(*sq).x = x;
	(*sq).y = y;
	(*sq).sq = s;
}

t_sq			*ft_find_square(unsigned int *matrix, unsigned int m,\
				unsigned int n)
{
	unsigned int	i;
	unsigned int	j;
	t_sq			*rez;

	i = -1;
	rez = malloc(sizeof(t_sq));
	rez->sq = 0;
	while (++i < m)
	{
		j = -1;
		while (++j < n)
		{
			if (!((matrix[i * n + j] == 0) || (i == 0) || (j == 0) ||\
					(matrix[(i - 1) * n + j - 1] == 0)))
			{
				matrix[i * n + j] = ft_min(matrix[(i - 1) * n + j - 1],\
					matrix[i * n + j - 1], matrix[(i - 1) * n + j]) + 1;
			}
			if (matrix[i * n + j] > rez->sq)
				ft_sq_update(rez, j, i, matrix[i * n + j]);
		}
	}
	return (rez);
}

void			ft_output(t_desc *desc, t_sq *rez, unsigned int *matrix)
{
	unsigned int	i;
	unsigned int	j;

	i = -1;
	while (++i < desc->lines)
	{
		j = -1;
		while (++j < desc->rows)
		{
			if (((i >= rez->y - rez->sq + 1) && (i <= rez->y)) &&\
					((j >= rez->x - rez->sq + 1) && (j <= rez->x)))
			{
				write(1, &desc->full, 1);
			}
			else
			{
				if (matrix[i * desc->rows + j] == 0)
					write(1, &desc->obstacle, 1);
				else
					write(1, &desc->empty, 1);
			}
		}
		write(1, "\n", 1);
	}
	free(rez);
}
