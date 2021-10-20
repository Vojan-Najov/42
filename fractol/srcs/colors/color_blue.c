#include "fractol.h"

void	color_blue(int *colors)
{
	int	i;
	int	color;

	i = 0;
	color = 0x03A0AB;
	while (i < 20)
	{
		colors[i] = color;
		++i;
		color -= 0x000500;
	}
	color = 0x1549;
	while (i < 50)
	{
		colors[i] = color;
		++i;
		color += 0x010101;
	}
	color = 0x2D0852;
	while (i < 70)
	{
		colors[i] = color;
		++i;
		color += 0x010101;
	}

	color = 0xFCF403;
	while (i < MAX_ITERATIONS)
	{
		colors[i] = color;
		++i;
		color -= 0x000800;
	}
	colors[i] = 0x0;
}
