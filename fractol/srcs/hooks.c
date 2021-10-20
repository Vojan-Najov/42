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

static int	deal_mouse(int button, int x, int y, t_fractol *fr);

void	define_hooks(t_fractol *fr)
{
	mlx_key_hook(fr->win_ptr, deal_key, fr);
	mlx_mouse_hook(fr->win_ptr, deal_mouse, fr);
}

static int	deal_key(int keycode, t_fractol *fr)
{
	if (keycode == ESC)
		completion(fr);
	else if (keycode == ARROW_LEFT)
		add_area(fr, -0.05, 0.);
	else if (keycode == ARROW_RIGHT)
		add_area(fr, 0.05, 0.);
	else if (keycode == ARROW_UP)
		add_area(fr, 0., 0.05);
	else if (keycode == ARROW_DOWN)
		add_area(fr, 0., -0.05);
	else if (keycode == Q_KEY)
		define_area(fr);
	else if (keycode == SPACE)
		define_colors(fr->colors, COLOR_NEXT);
	if (ft_strcmp(fr->name, MANDELBROT) == 0)
		fill_mandelbrot_set(fr);
	else
		fill_julia_set(fr);
	return (1);
}

static int	deal_mouse(int button, int x, int y, t_fractol *fr)
{
	t_complex	cursor;
	t_complex	centre;
	double		ratio;

	centre.re = fr->area[RE_MIN] + (WIDTH / 2) * fr->area[RE_FACTOR];
	centre.im = fr->area[IM_MAX] - (HEIGHT / 2) * fr->area[IM_FACTOR];
	cursor.re = fr->area[RE_MIN] + x * fr->area[RE_FACTOR];
	cursor.im = fr->area[IM_MAX] - y * fr->area[IM_FACTOR];
	if (button == MOUSE_LEFT_BUTTON)
	{
		add_area(fr, -centre.re + cursor.re, -centre.im + cursor.im);
	}
	else if (button == MOUSE_WHEEL_UP || button == MOUSE_WHEEL_DOWN)
	{
		if (button == MOUSE_WHEEL_UP)
			ratio = 1.1;
		else
			ratio = 0.9;
		mult_area(fr, ratio, ratio);
		cursor.re *= (1 - ratio);
		cursor.im *= (1 - ratio);
		add_area(fr, cursor.re, cursor.im);
	}
	else if (button == MOUSE_RIGHT_BUTTON)
	{
		printf("x = %d       y = %d\n", x, y);
	}
	if (ft_strcmp(fr->name, MANDELBROT) == 0)
		fill_mandelbrot_set(fr);
	else
		fill_julia_set(fr);
	return (1);
}
