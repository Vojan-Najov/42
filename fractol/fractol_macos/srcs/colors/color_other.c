/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_other.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 18:22:36 by ccartman          #+#    #+#             */
/*   Updated: 2021/10/24 18:22:37 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	color_other(int *colors)
{
	int	r;
	int	g;
	int	b;
	int	i;

	i = 0;
	r = 0;
	while (r <= 0x99)
	{
		g = 0;
		while (g <= 0xCC)
		{
			b = 0;
			while (b <= 0xCC)
			{
				colors[i++] = (r << 16) + (g << 8) + b;
				b += 0x33;
			}
			g += 0x33;
		}
		r += 0x33;
	}
	colors[MAX_ITERATIONS] = 0x0;
}
