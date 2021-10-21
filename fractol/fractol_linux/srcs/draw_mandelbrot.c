#include "fractol.h"

int		mandelbrot_recurent_cycle(t_complex *c);

void	fill_mandelbrot_set(t_fractol *fr)
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
			iter = mandelbrot_recurent_cycle(&c);
			pixel_put(fr, x, y, iter);
			++x;
		}
		++y;
	}
	mlx_put_image_to_window(fr->mlx_ptr, fr->win_ptr, fr->img_ptr, 0, 0);
}

int	mandelbrot_recurent_cycle(t_complex *c)
{
	int			iter;
	t_complex	z;

	init_complex(&z, c->re, c->im);
	iter = 0;
	while (iter < MAX_ITERATIONS)
	{
		if (z.re * z.re + z.im * z.im > 4)
			break ;
		x2_complex(&z);
		add_complex(&z, c);
		++iter;
	}
	return (iter);
}
