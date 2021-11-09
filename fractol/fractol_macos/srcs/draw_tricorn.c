/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_tricorn.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 18:20:21 by ccartman          #+#    #+#             */
/*   Updated: 2021/10/24 18:20:24 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		tricorn_recurent_cycle(t_complex *c);

void	fill_tricorn_set(t_fractol *fr)
{
	t_complex	c;
	int			y;
	int			x;
	int			iter;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		c.im = fr->area[IM_MAX] - y * fr->area[IM_FACTOR];
		while (x < WIDTH)
		{
			c.re = fr->area[RE_MIN] + x * fr->area[RE_FACTOR];
			iter = tricorn_recurent_cycle(&c);
			pixel_put(fr, x, y, iter);
			++x;
		}
		++y;
	}
	mlx_put_image_to_window(fr->mlx_ptr, fr->win_ptr, fr->img_ptr, 0, 0);
}

int	tricorn_recurent_cycle(t_complex *c)
{
	int			iter;
	t_complex	z;

	init_complex(&z, c->re, c->im);
	iter = 0;
	while (iter < MAX_ITERATIONS)
	{
		if (z.re * z.re + z.im * z.im - 4. > 0)
			break ;
		x2_complex(&z);
		z.im = -z.im;
		add_complex(&z, c);
		++iter;
	}
	return (iter);
}
