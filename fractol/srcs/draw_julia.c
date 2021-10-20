#include "fractol.h"

static void	pixel_put(t_fractol *fr, int x, int y, int iter);

int	julia_recurent_cycle(t_complex *z, t_complex *c);

void	fill_julia_set(t_fractol *fr)
{
	t_complex	z;
	int			y;
	int			x;
	int			iter;
	//t_complex	centre;
	
	//centre.re = fr->area[RE_MIN] + (WIDTH / 2) * fr->area[RE_FACTOR];
	//centre.im = fr->area[IM_MAX] - (HEIGHT / 2) * fr->area[IM_FACTOR];
	//add_area(fr, -centre.re, -centre.im);
	//mult_area(fr, 2., 2.);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			z.im = fr->area[IM_MAX] - y * fr->area[IM_FACTOR];
			z.re = fr->area[RE_MIN] + x * fr->area[RE_FACTOR];
			iter = julia_recurent_cycle(&z, &fr->julc);
			pixel_put(fr, x, y, iter);
			++x;
		}
		++y;
	}
	mlx_put_image_to_window(fr->mlx_ptr, fr->win_ptr, fr->img_ptr, 0, 0);
}

int julia_recurent_cycle(t_complex *z, t_complex *c)
{
	int			iter;

	//x2_complex(z);
	add_complex(z, c);
	iter = 0;
	while (iter < MAX_ITERATIONS)
	{
		if (z->re * z->re + z->im * z->im > 4)
			break ;
		x2_complex(z);
		add_complex(z, c);
		++iter;
	}
	return (iter);
}

static void	pixel_put(t_fractol *fr, int x, int y, int iter)
{
	int		color;
	char	*dst;

	color = fr->colors[iter];
	dst = fr->addr_ptr + y * fr->size_line + x * fr->bits_per_pixel / 8;
	*(unsigned int *) dst = color;
}
