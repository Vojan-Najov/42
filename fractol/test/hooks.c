#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
//#include <X.h>
#define WIDTH 1920
#define HEIGHT 1080

int	ft_key_hook(int keycode, void	*param)
{
	(void) param;
	printf("KEY code is %d\n", keycode);
	return (1);
}

int	ft_mouse_hook(int button, int x, int y, void *param)
{
	(void) param;
	printf("(%d, %d) button is %d\n", x, y, button);
	return (1);
}

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*param;

	param = malloc(sizeof(1024));
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, WIDTH, HEIGHT, "HOOKING");
	mlx_key_hook(win_ptr, ft_key_hook, param);
	mlx_mouse_hook(win_ptr, ft_mouse_hook, param);
	mlx_loop(mlx_ptr);
}
