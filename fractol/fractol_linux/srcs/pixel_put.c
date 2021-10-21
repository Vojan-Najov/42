#include "fractol.h"

void	pixel_put(t_fractol *fr, int x, int y, int iter)
{
	int		color;
	char	*dst;

	color = fr->colors[iter];
	dst = fr->addr_ptr + y * fr->size_line + x * fr->bits_per_pixel / 8;
	*(unsigned int *) dst = color;
}
