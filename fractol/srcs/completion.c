#include "fractol.h"

void	completion(t_fractol *fr)
{
	mlx_destroy_image(fr->mlx_ptr, fr->img_ptr);
	mlx_destroy_window(fr->mlx_ptr, fr->win_ptr);
	free(fr->colors);
	exit(0);
}
