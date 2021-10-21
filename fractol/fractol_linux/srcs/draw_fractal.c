#include "fractol.h"

void	draw_fractal(t_fractol *fr)
{
	if (ft_strcmp(fr->name, MANDELBROT) == 0)
		fill_mandelbrot_set(fr);
	else if (ft_strcmp(fr->name, JULIA) == 0)
		fill_julia_set(fr);
}
