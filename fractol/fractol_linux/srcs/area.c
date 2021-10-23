/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   area.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 17:52:01 by ccartman          #+#    #+#             */
/*   Updated: 2021/10/16 18:12:12 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	init_area(t_fractol *fr, double re_min, double re_max, \
													double im_min);

static void	init_julia_area(t_fractol *fr);

void	define_area(t_fractol *fr)
{
	if (ft_strcmp(fr->name, MANDELBROT) == 0)
		init_area(fr, -2.0, 1.0, -1.2);
	else if (ft_strcmp(fr->name, JULIA) == 0)
	{
		init_julia_area(fr);
	}
	else if (ft_strcmp(fr->name, BURNING_SHIP) == 0)
		init_area(fr, -1.5, 2.0, -1.0);
	else if (ft_strcmp(fr->name, TRICORN) == 0)
		init_area(fr, -2.5, 2., -2.0);
}

static void	init_area(t_fractol *fr, double re_min, double re_max, \
													double im_min)
{
	fr->area[RE_MIN] = re_min;
	fr->area[RE_MAX] = re_max;
	fr->area[IM_MIN] = im_min;
	fr->area[IM_MAX] = fr->area[IM_MIN] + \
					   (fr->area[RE_MAX] - fr->area[RE_MIN]) * HEIGHT / WIDTH;
	fr->area[RE_FACTOR] = (fr->area[RE_MAX] - fr->area[RE_MIN]) / (WIDTH - 1);
	fr->area[IM_FACTOR] = (fr->area[IM_MAX] - fr->area[IM_MIN]) / (HEIGHT - 1);
}

static void	init_julia_area(t_fractol *fr)
{
	double	r;

	r = (1.0 + sqrt(1.0 + 4 * sqrt(pow(fr->julc.re, 2.0) + \
									pow(fr->julc.im, 2.0)))) / 2.0;
	fr->radius = r;
	fr->area[RE_MIN] = -1.1 * r;
	fr->area[RE_MAX] = 1.1 * r;
	fr->area[IM_MIN] = -1.1 * r;
	fr->area[IM_MAX] = fr->area[IM_MIN] + \
					   (fr->area[RE_MAX] - fr->area[RE_MIN]) * HEIGHT / WIDTH;
	fr->area[RE_FACTOR] = (fr->area[RE_MAX] - fr->area[RE_MIN]) / (WIDTH - 1);
	fr->area[IM_FACTOR] = (fr->area[IM_MAX] - fr->area[IM_MIN]) / (HEIGHT - 1);
}

void	add_area(t_fractol *fr, double dx, double dy)
{
	fr->area[RE_MIN] += dx;
	fr->area[RE_MAX] += dx;
	fr->area[IM_MIN] += dy;
	fr->area[IM_MAX] = fr->area[IM_MIN] + \
					   (fr->area[RE_MAX] - fr->area[RE_MIN]) * HEIGHT / WIDTH;
	fr->area[RE_FACTOR] = (fr->area[RE_MAX] - fr->area[RE_MIN]) / (WIDTH - 1);
	fr->area[IM_FACTOR] = (fr->area[IM_MAX] - fr->area[IM_MIN]) / (HEIGHT - 1);
}

void	mult_area(t_fractol *fr, double x_factor, double y_factor)
{
	fr->area[RE_MIN] *= x_factor;
	fr->area[RE_MAX] *= x_factor;
	fr->area[IM_MIN] *= y_factor;
	fr->area[IM_MAX] = fr->area[IM_MIN] + \
					   (fr->area[RE_MAX] - fr->area[RE_MIN]) * HEIGHT / WIDTH;
	fr->area[RE_FACTOR] = (fr->area[RE_MAX] - fr->area[RE_MIN]) / (WIDTH - 1);
	fr->area[IM_FACTOR] = (fr->area[IM_MAX] - fr->area[IM_MIN]) / (HEIGHT - 1);
}
