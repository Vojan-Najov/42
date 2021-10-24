/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_gray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 18:22:09 by ccartman          #+#    #+#             */
/*   Updated: 2021/10/24 18:22:11 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	color_gray(int *colors)
{
	int	i;

	colors[0] = 0x0;
	i = 1;
	while (i < MAX_ITERATIONS - 1)
	{
		if (i % 2)
			colors[i] = colors[i - 1] + 0x030303;
		else
			colors[i] = colors[i - 1] + 0x020202;
		++i;
	}
	colors[MAX_ITERATIONS - 1] = 0xFFFFFF;
	colors[MAX_ITERATIONS] = 0x0;
}
