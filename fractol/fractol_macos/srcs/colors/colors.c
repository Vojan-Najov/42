/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 18:22:51 by ccartman          #+#    #+#             */
/*   Updated: 2021/10/24 18:22:53 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	define_colors(int *colors, int flag)
{
	static int	theme;

	if (flag == COLOR_DEFAULT)
		color_red(colors);
	else
	{
		theme = (theme + 1) % 4;
		if (theme == COLOR_RED)
			color_red(colors);
		else if (theme == COLOR_GRAY)
			color_gray(colors);
		else if (theme == COLOR_BLUE)
			color_blue(colors);
		else if (MAX_ITERATIONS == 100)
			color_other(colors);
	}
}
