/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 18:19:25 by ccartman          #+#    #+#             */
/*   Updated: 2021/10/24 18:19:27 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_fractal(t_fractol *fr)
{
	if (ft_strcmp(fr->name, MANDELBROT) == 0)
		fill_mandelbrot_set(fr);
	else if (ft_strcmp(fr->name, JULIA) == 0)
		fill_julia_set(fr);
	else if (ft_strcmp(fr->name, BURNING_SHIP) == 0)
		fill_burning_ship_set(fr);
	else if (ft_strcmp(fr->name, TRICORN) == 0)
		fill_tricorn_set(fr);
}
