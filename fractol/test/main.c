/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 23:00:18 by ccartman          #+#    #+#             */
/*   Updated: 2021/10/16 17:50:24 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	change_area(t_mlx *data, double dx, double dy);

//
void	initialization(t_mlx *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
	{
		perror("mlx_int()");
		exit(EXIT_FAILURE);
	}
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "FRACTOL");
	if (!data->win_ptr)
	{
		perror("mlx_new_window()");
		exit(EXIT_FAILURE);
	}
	data->img_ptr = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	if (!data->img_ptr)
	{
		perror("mlx_new_image()");
		exit(EXIT_FAILURE);
	}
	data->addr_ptr = mlx_get_data_addr(data->img_ptr, &data->bits_per_pixel, \
									&data->size_line, &data->endian);
}
//

void	init_complex(t_complex *c, double re, double im)
{
	c->re = re;
	c->im = im;
}

void	x2_complex(t_complex *c)
{
	double	re;
	double	im;

	re = c->re * c->re - c->im * c->im;
	im = 2.0 * c->re * c->im;
	c->re = re;
	c->im = im;
}

void	add_complex(t_complex *c, t_complex *a)
{
	c->re += a->re;
	c->im += a->im;
}

void	completion(t_mlx *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	exit(0);
}

void	pixel_put(t_mlx *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr_ptr + y * data->size_line + x * data->bits_per_pixel / 8;
	*(unsigned int *)dst = color;
}

void	color_pixel(t_mlx *data, int x, int y, int iter)
{
	int	red;
	int	green;
	int	blue;
	int	color;
	double	t;

//	red = (int)(9. * (1. - t) * pow(t, 3.) * 255.);
//	green = (int)(15. * pow((1. - t), 2) * pow(t, 2) * 255);
//	blue = (int) (8.5 * pow((1. - t), 3) * t * 255.);
//	color = red;
//	color <<= 16;
//	color += green;
//	color <<= 8;
//	color += blue;

	
	t = (double) iter / (double) MAX_ITERATIONS;

	red = (int) (9. * (1. - t) * t * t * t * 255.);
	green = (int) (15. * pow((1. - t), 2) * pow(t, 2) * 255);
	blue = (int) (8.5 * pow((1. - t), 3) * t * 255.);
	color = red;
	color <<= 16;
	color += green;
	color <<= 8;
	color += blue;

	color = (MAX_ITERATIONS - iter) * 0x030303;
// gray
//
//	if (iter == MAX_ITERATIONS)
//	{
//		color = 0x0;
//	}
//	else
//		color = 0xfcfcfc;

	pixel_put(data, x, y, color);
}

void	fill_mandelbrot_set(t_mlx *data, double dx, double dy)
{
	t_complex	c;
	t_complex	z;
	int			y;
	int			x;
	int			iter;
	int			inside;	//

	data->area[RE_MIN] += dx;
	data->area[RE_MAX] += dx;
	data->area[IM_MIN] += dy;
	data->area[IM_MAX] += dy;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		c.im = data->area[IM_MAX] - y * data->area[IM_FACTOR];
		while (x < WIDTH)
		{
			c.re = data->area[RE_MIN] + x * data->area[RE_FACTOR];
			iter = 0;
			init_complex(&z, c.re, c.im);
			inside = 1; //
			while (iter < MAX_ITERATIONS)
			{
				if (z.re * z.re + z.im * z.im - 4 > g_epsilon)
				{
					inside = 0; //
					break ;
				}
				x2_complex(&z);
				add_complex(&z, &c);
				++iter;
			}
			color_pixel(data, x, y, iter);
			++x;
		}
		++y;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0 , 0);
}

int		deal_key(int keycode, t_mlx *data)
{
	if (keycode == 53)
		completion(data);
	else if (keycode == 123)
		fill_mandelbrot_set(data, -0.05, 0);
	else if (keycode == 124)
		fill_mandelbrot_set(data, 0.05, 0);
	else if (keycode == 125)
		fill_mandelbrot_set(data, 0., -0.05);
	else if (keycode == 126)
		fill_mandelbrot_set(data, 0., 0.05);
	else if (keycode == 12)
	{
		change_area(data, 1.1, 1.1);
		fill_mandelbrot_set(data, 0, 0);
	}
	else if (keycode == 13)
	{
		change_area(data, 0.9, 0.9);
		fill_mandelbrot_set(data, 0, 0);
	}
	return (0);
}

int		deal_mouse(int buttom, int x, int y, t_mlx *data)
{
	t_complex nc;


	(void) data;
	if (buttom == 1)
	{
		nc.re = data->area[RE_MIN] + x * data->area[RE_FACTOR];
		nc.im = data->area[IM_MAX] - y * data->area[IM_FACTOR];
		fill_mandelbrot_set(data, nc.re, nc.im);
		
	}
	printf("%d\n", buttom);
	printf("x = %d    y = %d\n", x, y);
	return (1);
}

void	draw_mandelbrot(t_mlx *data)
{
	mlx_hook(data->win_ptr, 2, 1L << 0, deal_key, data);
	mlx_mouse_hook(data->win_ptr, deal_mouse, data);
	fill_mandelbrot_set(data, 0, 0);
	mlx_loop(data->mlx_ptr);
}

void	change_area(t_mlx *data, double dx, double dy)
{
	double	*a;

	a = data->area;
	a[RE_MIN] *= dx;
	a[RE_MAX] *= dx;
	a[IM_MIN] *= dy;
	a[IM_MAX] *= dy;
    a[RE_FACTOR] = (a[RE_MAX] - a[RE_MIN]) / (WIDTH - 1);
	a[IM_FACTOR] = (a[IM_MAX] - a[IM_MIN]) / (HEIGHT - 1);
	
}

void	define_area(t_mlx *data)
{
	data->area[RE_MIN] = -2.0;
	data->area[RE_MAX] = 1.0;
	data->area[IM_MIN] = -1.2;
	data->area[IM_MAX] = data->area[IM_MIN] + (data->area[RE_MAX] - \
						data->area[RE_MIN]) * HEIGHT / WIDTH;
	data->area[RE_FACTOR] = (data->area[RE_MAX] - data->area[RE_MIN]) / (WIDTH - 1);
	data->area[IM_FACTOR] = (data->area[IM_MAX] - data->area[IM_MIN]) / (HEIGHT - 1);
}

int	main(int argc, char **argv)
{
	t_mlx	data;

	(void) argc;
	(void) argv;
	initialization(&data);
	define_area(&data);
	draw_mandelbrot(&data);
	return (0);
}
