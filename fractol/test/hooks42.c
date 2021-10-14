#include "mlx.h"
#include <stdio.h>

int	deal_key(int key, void *param)
{
	(void) param;
	printf("key kod is %d\n", key);
	return (0);
}

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "hooks42");
	mlx_key_hook(win_ptr, deal_key, (void *) 0);
	mlx_loop(mlx_ptr);
}
