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

void	define_area(t_fractol *fr)
{
	if (ft_strcmp(fr->name, JULIA) == 0)
	{
		define_julia_area(fr);
		return ;
	}
	fr->area[RE_MIN] = -2.0;
	fr->area[RE_MAX] = 1.0;
	fr->area[IM_MIN] = -1.2;
	fr->area[IM_MAX] = fr->area[IM_MIN] + \
					   (fr->area[RE_MAX] - fr->area[RE_MIN]) * HEIGHT / WIDTH;
	fr->area[RE_FACTOR] = (fr->area[RE_MAX] - fr->area[RE_MIN]) / (WIDTH - 1);
	fr->area[IM_FACTOR] = (fr->area[IM_MAX] - fr->area[IM_MIN]) / (HEIGHT - 1);
}

void	define_julia_area(t_fractol *fr)
{
	double	r;

	r = (1.0 + sqrt(1.0 + 4 * sqrt(pow(fr->julc.re, 2.0) + \
									pow(fr->julc.im, 2.0)))) / 2.0;
	fr->radius = r;
	fr->area[RE_MIN] = -r;
	fr->area[RE_MAX] = r;
	fr->area[IM_MIN] = -r;
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
