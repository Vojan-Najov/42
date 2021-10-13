#include "mlx.h"

int	main()
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	if (!mlx_ptr)
		return (1);
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "test42");
	if (!win_ptr)
		return (2);
	//mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0xFFFFFF);
	mlx_string_put(mlx_ptr, win_ptr, 0, 0, 0xFF0000, "42 fract-ol");
	int x, y, lx, ly;
	y = 225;
	lx = 50;
	ly = 50;
	while (ly--)
	{
		x = 225;
		lx = 50;
		while (lx--)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xFFFFFF);
			++x;
		}
		++y;
	}
	mlx_string_put(mlx_ptr, win_ptr, 20, 20, 0x00FF00, "________________");
	mlx_loop(mlx_ptr);
	return (0);
}

//	int	mlx_clear_window(void *mlx_ptr, void *win_ptr);
//	int	mlx_destroy_window(void *mlx_ptr, void *win_ptr);
//	
//	keysymdef.h
//	X.h
//
