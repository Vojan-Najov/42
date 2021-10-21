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
/*
int	burning_ship_recurent_cycle(t_complex *c)
{
	int			iter;
	t_complex	z;
	double		fz;

	init_complex(&z, 0., 0.);
	iter = 0;
	fz = z.re * z.re + z.im * z.im;
	while (fz <= 4 && iter < 100)
	{
		double x;
		x = z.re * z.re - z.im * z.im + c->re;
		z.im = -2 * z.re * z.im + c->im;
		z.re = x;
		fz = z.re * z.re + z.im * z.im;
		++iter;
		z.re = x;
	}
	return (iter);
}
*/

int	burning_ship_recurent_cycle(t_complex *c)
{
	int			iter;
	t_complex	z;
	double		fz;

	init_complex(&z, 0., 0.);
	iter = 0;
	fz = z.re * z.re + z.im * z.im;
	while (fz <= 4 && iter < 100)
	{
		double x;
		x = z.re * z.re - z.im * z.im - c->re;
		z.im = 2 * z.re * z.im;
		if (z.im < 0)
			z.im = -z.im;
		z.im -= c->im;
		z.re = x;
		fz = z.re * z.re + z.im * z.im;
		++iter;
	}
	return (iter);
}
