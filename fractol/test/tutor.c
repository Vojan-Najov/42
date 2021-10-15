#include <mlx.h>
#include <stdio.h>
#define WIDTH 1920
#define HEIGHT 1080

typedef struct	s_data
{
	void	*img_ptr;
	char	*addr_ptr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}				t_data;

void	ft_square(t_data *data, int length, int color);

void	ft_cyrcle(t_data *data, int radius, int color);

void	ft_rectangle(t_data *data, int length, int width, int color);

void	ft_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr_ptr + (y * data->size_line + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_data	img;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, WIDTH, HEIGHT, "HELLO");
	img.img_ptr = mlx_new_image(mlx_ptr, WIDTH, HEIGHT);
	img.addr_ptr = mlx_get_data_addr(img.img_ptr, &img.bits_per_pixel, \
									&img.size_line, &img.endian);
	ft_cyrcle(&img, 300, 0x000AA245);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img.img_ptr, 0, 0);
	ft_square(&img, 100, 0x0000FF00);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img.img_ptr, 0, 0);
	ft_mlx_pixel_put(&img, WIDTH / 2, HEIGHT / 2, 0x00FF0000);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img.img_ptr, 0, 0);
	ft_rectangle(&img, 50, 40, 0x00FF0000);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img.img_ptr, 0, 0);
	ft_rectangle(&img, 50, 40, 0x00FFA500);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img.img_ptr, 0, 0);
	ft_rectangle(&img, 50, 40, 0x00FFFF00);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img.img_ptr, 0, 0);
	ft_rectangle(&img, 50, 40, 0x0000FF00);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img.img_ptr, 0, 0);
	ft_rectangle(&img, 50, 40, 0x0042AAFF);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img.img_ptr, 0, 0);
	ft_rectangle(&img, 50, 40, 0x000000FF);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img.img_ptr, 0, 0);
	ft_rectangle(&img, 50, 40, 0x008b00FF);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img.img_ptr, 0, 0);
	mlx_loop(mlx_ptr);
}

void	ft_square(t_data *data, int length, int color)
{
	int	x;
	int	y;
	int	i;
	int	j;

	y = (HEIGHT / 2) - length / 2;
	i = 0;
	while (i < length)
	{
		j = 0;
		x = (WIDTH / 2) - length / 2;
		while (j < length)
		{
			ft_mlx_pixel_put(data, x, y, color);
			++x;
			++j;;
		}
		color += 0x00101000;
		++y;
		++i;
	}
}

void	ft_rectangle(t_data *data, int length, int width, int color)
{
	static int save_x;
	static int save_y;
	int	x;
	int y;
	int	i;
	int	j;

	printf("x = %d, y = %d\n", save_x, save_y);
	i = 0;
	y = 0;
	while (i < length)
	{
		x = save_x;
		j = 0;
		while (j < width)
		{
			//printf("1");
			ft_mlx_pixel_put(data, x, y, color);
			++j;
			++x;
		}
		++i;
		++y;
	}
	save_x = x;
	save_y = 0;
	printf("rectangle\n");
}

void	ft_cyrcle(t_data *data, int radius, int color)
{
	int	x;
	int y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if ((x - WIDTH / 2) * (x - WIDTH / 2) + \
					(y - HEIGHT / 2) * (y - HEIGHT / 2) <= radius * radius)
			{
				ft_mlx_pixel_put(data, x, y, color);
			}
			color += 50;
			++x;
		}
		color -= 2000;
		++y;
	}
}

























