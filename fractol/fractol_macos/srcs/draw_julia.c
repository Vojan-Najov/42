/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_julia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 18:19:44 by ccartman          #+#    #+#             */
/*   Updated: 2021/10/24 18:19:54 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	julia_recurent_cycle(t_complex *z, t_complex *c, \
												double radius);

void	init_julia_set(t_fractol *fr, int argc, char **argv)
{
	if (argc == 2)
	{
		fr->julc.re = -0.74543;
		fr->julc.im = 0.11301;
	}
	else if (argc != 4 || !check_float(argv[2]) || !check_float(argv[3]))
	{
		print_help();
		exit(EXIT_FAILURE);
	}
	else
	{
		fr->julc.re = ft_atof(argv[2]);
		fr->julc.im = ft_atof(argv[3]);
	}
	fr->right_button = 0;
}

void	fill_julia_set(t_fractol *fr)
{
	t_complex	z;
	int			y;
	int			x;
	int			iter;
	double		r;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			z.im = fr->area[IM_MAX] - y * fr->area[IM_FACTOR];
			z.re = fr->area[RE_MIN] + x * fr->area[RE_FACTOR];
			iter = julia_recurent_cycle(&z, &fr->julc, fr->radius);
			pixel_put(fr, x, y, iter);
			++x;
		}
		++y;
	}
	mlx_put_image_to_window(fr->mlx_ptr, fr->win_ptr, fr->img_ptr, 0, 0);
}

static int	julia_recurent_cycle(t_complex *z, t_complex *c, \
												double radius)
{
	int	iter;

	x2_complex(z);
	add_complex(z, c);
	iter = 0;
	while (iter < MAX_ITERATIONS)
	{
		if (z->re * z->re + z->im * z->im - radius * radius > 0)
			break ;
		x2_complex(z);
		add_complex(z, c);
		++iter;
	}
	return (iter);
}
