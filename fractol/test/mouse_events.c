#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#define ESC 65307//53

typedef struct	s_param
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		mouse_in;
}				t_param;

int	ft_close_win(int keycode, t_param *param)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(param->mlx_ptr, param->win_ptr);
		exit(0);
	}
	else
	{
		printf("key is %d\n", keycode);
	}
	return (keycode);
}

int	deal_mouse(int button, int x, int y, t_param *param)
{
	printf("x = %d    y = %d\n", x, y);
	printf("b = %d\n", button);
	(void) param;
	if (button == 3)
		param->mouse_in = 1;
	return (1);
}

int	deal_mouse_in(int button, int x, int y, t_param *param)
{
	(void) x;
	(void) y;
	(void) button;
	//printf("x = %d    y = %d\n", x, y);
	//printf("b = %d\n", buttom);
	(void) param;
	if (button == 3)
		printf("3 ---   x = %d   y = %d\n", x, y);
	printf("hello\n");
	return (1);
}

int	deal_mouse_off(int buttom, int x, int y, t_param *param)
{
	(void) x;
	(void) y;
	(void) buttom;
	//printf("x = %d    y = %d\n", x, y);
	//printf("b = %d\n", buttom);
	(void) param;
	printf("bye\n");
	return (1);
}

int	deal_motion(int button, int x, int y, t_param *param)
{
	(void) (button + x + y);
	if (param->mouse_in)
		printf("ooo\n");
	return (1);
}
int	main(void)
{
	t_param	param;
	//int w;
	//int h;


	param.mlx_ptr = mlx_init();
	//mlx_get_screen_size(param.mlx_ptr, &w, &h);
	param.win_ptr = mlx_new_window(param.mlx_ptr, 500, 500, "events");
	mlx_hook(param.win_ptr, 2, 1L << 0, ft_close_win, &param);
	mlx_hook(param.win_ptr, 4, 1L << 2, deal_mouse, &param);
	mlx_hook(param.win_ptr, 6, 1L << 10, deal_motion, &param);
	
	mlx_hook(param.win_ptr, 7, 1L << 4, deal_mouse_in, &param);
	mlx_hook(param.win_ptr, 8, 1L << 5, deal_mouse_off, &param);

	mlx_loop(param.mlx_ptr);
}
