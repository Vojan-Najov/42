/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_red.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 18:22:18 by ccartman          #+#    #+#             */
/*   Updated: 2021/10/24 18:22:22 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	color_red(int *colors)
{
	int		i;
	double	dc;

	i = 0;
	dc = 0x100 / MAX_ITERATIONS;
	while (i < MAX_ITERATIONS)
	{
		colors[i] = ((int)(dc * i)) << 16;
		++i;
	}
	colors[MAX_ITERATIONS] = 0x0;
}
