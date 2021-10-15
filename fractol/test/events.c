#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#define ESC 53

typedef struct	s_param
{
	void	*mlx_ptr;
	void	*win_ptr;
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

int	deal_focus(int buttom, int x, int y, t_param *param)
{
	printf
}

int	main(void)
{
	t_param	param;


	param.mlx_ptr = mlx_init();
	param.win_ptr = mlx_new_window(param.mlx_ptr, 500, 500, "events");
	mlx_hook(param.win_ptr, 2, 1L << 0, ft_close_win, &param);
	mlx_hook(param.win_ptr, 9, 1L << 21, deal_focus, &param);
	mlx_loop(param.mlx_ptr);
}
