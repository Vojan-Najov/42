/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_burning_ship.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 18:19:09 by ccartman          #+#    #+#             */
/*   Updated: 2021/10/24 18:19:13 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		burning_ship_recurent_cycle(t_complex *c);

void	fill_burning_ship_set(t_fractol *fr)
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
			iter = burning_ship_recurent_cycle(&c);
			pixel_put(fr, x, y, iter);
			++x;
		}
		++y;
	}
	mlx_put_image_to_window(fr->mlx_ptr, fr->win_ptr, fr->img_ptr, 0, 0);
}

int	burning_ship_recurent_cycle(t_complex *c)
{
	int			iter;
	double		x;	
	t_complex	z;

	init_complex(&z, c->re, c->im);
	iter = 0;
	while (iter < MAX_ITERATIONS)
	{
		if (z.re * z.re + z.im * z.im - 4. > 0.)
			break ;
		x2_complex(&z);
		z.im = fabs(z.im);
		subtract_complex(&z, c);
		++iter;
	}
	return (iter);
}
