/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 15:57:30 by ccartman          #+#    #+#             */
/*   Updated: 2021/10/16 18:19:52 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	deal_key(int keycode, t_fractol *fr);

static int	deal_button(int button, int x, int y, t_fractol *fr);

static int	deal_motion_notify(int x, int y, t_fractol *fr);

void	define_hooks(t_fractol *fr)
{
	mlx_key_hook(fr->win_ptr, deal_key, fr);
	mlx_hook(fr->win_ptr, 4, 1L << 2, deal_button, fr);
	mlx_hook(fr->win_ptr, MOTION_NOTIFY, 1L << 10, \
								deal_motion_notify, fr);
	mlx_hook(fr->win_ptr, DESTROY_NOTIFY, DEFAULT_MASK, completion, fr);
}

static int	deal_key(int keycode, t_fractol *fr)
{
	if (keycode == ESC)
		completion(fr);
	else if (keycode == ARROW_LEFT)
		add_area(fr, -10 * fr->area[RE_FACTOR], 0.);
	else if (keycode == ARROW_RIGHT)
		add_area(fr, 10 * fr->area[RE_FACTOR], 0.);
	else if (keycode == ARROW_UP)
		add_area(fr, 0., 10 * fr->area[IM_FACTOR]);
	else if (keycode == ARROW_DOWN)
		add_area(fr, 0., -10 * fr->area[IM_FACTOR]);
	else if (keycode == Q_KEY)
		define_area(fr);
	else if (keycode == SPACE)
		define_colors(fr->colors, COLOR_NEXT);
	draw_fractal(fr);
	return (1);
}

static int	deal_button(int button, int x, int y, t_fractol *fr)
{
	t_complex	cursor;
	t_complex	centre;
	double		ratio;

	centre.re = fr->area[RE_MIN] + (WIDTH / 2) * fr->area[RE_FACTOR];
	centre.im = fr->area[IM_MAX] - (HEIGHT / 2) * fr->area[IM_FACTOR];
	cursor.re = fr->area[RE_MIN] + x * fr->area[RE_FACTOR];
	cursor.im = fr->area[IM_MAX] - y * fr->area[IM_FACTOR];
	if (button == MOUSE_LEFT_BUTTON)
		add_area(fr, -centre.re + cursor.re, -centre.im + cursor.im);
	else if (button == MOUSE_WHEEL_UP || button == MOUSE_WHEEL_DOWN)
	{
		if (button == MOUSE_WHEEL_UP)
			ratio = 1.1;
		else
			ratio = 0.9;
		mult_area(fr, ratio, ratio);
		add_area(fr, (1 - ratio) * cursor.re, (1 - ratio) * cursor.im);
	}
	draw_fractal(fr);
	return (1);
}

static int	deal_motion_notify(int x, int y, t_fractol *fr)
{
	if (ft_strcmp(fr->name, JULIA) == 0)
	{
		fr->julc.re = fr->area[RE_MIN] + x * fr->area[RE_FACTOR];
		fr->julc.re = fr->area[IM_MAX] - y * fr->area[IM_FACTOR];
		define_area(fr);
		fill_julia_set(fr);
	}
	return (1);
}
