#include "fractol.h"

void	color_red(int *colors)
{
	int	i;
	double	dc;

	i = 0;
	dc = 0x100 / MAX_ITERATIONS;
	while (i < MAX_ITERATIONS)
	{
		colors[i] = ((int) (dc * i)) << 16;
		++i;
	}
	colors[MAX_ITERATIONS] = 0x0;
}
