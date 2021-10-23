#include "fractol.h"

void	draw_fractal(t_fractol *fr)
{
	if (ft_strcmp(fr->name, MANDELBROT) == 0)
		fill_mandelbrot_set(fr);
	else if (ft_strcmp(fr->name, JULIA) == 0)
		fill_julia_set(fr);
	else if (ft_strcmp(fr->name, BURNING_SHIP) == 0)
		fill_burning_ship_set(fr);
	else if (ft_strcmp(fr->name, TRICORN) == 0)
		fill_tricorn_set(fr);
}
