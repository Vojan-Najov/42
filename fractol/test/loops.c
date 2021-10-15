#include <mlx.h>
#include <stdio.h>
#include <unistd.h>
#define WIDTH 1920
#define HEIGHT 1080

typedef	struct	s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*addr_ptr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}				t_data;
/*
void	ft_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	unsigned int	*dst;

	dst = (unsigned int *)(data->addr_ptr + (y * data->size_line) + \
			(x * data->bits_per_pixel / 8));
	*dst = get_color_value(data->mlx_ptr, color); // for other endian
	*dst = (unsigned int) color;
}
*/

void	ft_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr_ptr + (y * data->size_line) + \
			(x * data->bits_per_pixel / 8);
	//*dst = get_color_value(data->mlx_ptr, color); // for other endian
	*(unsigned int *)dst = (unsigned int) color;
}

int		render_next_frame(t_data *data)
{
	static unsigned int	count;
	int	x;
	int	y;
	enum color {
		red,
		green,
		blue
	};
	int colors[] = {0x00FF0000, 0x0000FF00, 0x000000FF};

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (count % 3 == red)
				ft_mlx_pixel_put(data, x, y, colors[red]);
			else if (count % 3 == green)
				ft_mlx_pixel_put(data, x, y, colors[green]);
			else if (count % 3 == blue)
				ft_mlx_pixel_put(data, x, y, colors[blue]);
			++x;
			//printf("color = %X\n", colors[count % 3]);
		}
		++y;
	}
	++count;
	usleep(50000);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);

//	(void) data;
	printf("%d\n", count);
	return (1);
}

/*
int		render_next_frame(t_data *data)
{
	static unsigned int	count;
	static int			color;
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			ft_mlx_pixel_put(data, x, y, color);
			++x;
		}
		++y;
	}
	if (count > 255)
		color += 0x100;
	if ( count > 510)
		color += 0x10000;
	else
		++color;
	++count;
	if (count > 255)
		color = 0x00FF00;
	if (count > 510)
		color = 0xFF0000;
	if (count > 765)
		color = 0;
	color += 10;
	++count;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);

	return (1);
}

*/

int	main(void)
{
	t_data	img;

	img.mlx_ptr = mlx_init();
	img.win_ptr = mlx_new_window(img.mlx_ptr, WIDTH, HEIGHT, "loops");
	img.img_ptr = mlx_new_image(img.mlx_ptr, WIDTH, HEIGHT);
	img.addr_ptr = mlx_get_data_addr(img.img_ptr, &img.bits_per_pixel, \
											&img.size_line, &img.endian);
	ft_mlx_pixel_put(&img, WIDTH/2, HEIGHT/2, 0xFF0000);
	mlx_put_image_to_window(img.mlx_ptr, img.win_ptr, img.img_ptr, 0, 0);
	mlx_loop_hook(img.mlx_ptr, render_next_frame, &img);
	mlx_loop(img.mlx_ptr);
}
