#include "fractol.h"

void	define_colors(int *colors, int flag)
{
	static int	theme;

	if (flag == COLOR_DEFAULT)
		color_red(colors);
	else
	{
		theme = (theme + 1) % 4;
		if (theme == COLOR_RED)
			color_red(colors);
		else if (theme == COLOR_GRAY)
			color_gray(colors);
		else if (theme == COLOR_BLUE)
			color_blue(colors);
		else if (MAX_ITERATIONS == 100)
			color_other(colors);
	}
}
