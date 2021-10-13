#include "mlx.h"
#include <math.h>
#include <stdio.h>

typedef struct	s_comlex
{
	double	re;
	double	im;
}				t_complex;

/*
t_complex	*init_complex(double re, double im)
{
	// лучше передавать аргументом адрес структуры заведеннной на стеке
	// вызывающей функции=. Для того чтобы ищбежать вызова фри.
	t_complex	*cmpl_ptr;

	cmpl_ptr = (t_complex) malloc(sizeof(*cmpl_ptr));
	if (!cmpl_ptr)
		exit(EXIT_FAILURE);
	cmpl_ptr->re = re;
	cmpl_ptr->im = im;
	return (cmpl_ptr);
}
*/

void	init_complex(t_complex *c_ptr, double re, double im)
{
	c_ptr->re = re;
	c_ptr->im = im;
}

int		image_height = 900;
int		image_width = 900;
int		max_iteration = 200;

int main()
{
	t_complex	factor;
	t_complex	c;
	t_complex	z;
	int			iteration;
	int			y;
	int			x;
	void		*mlx_ptr;
	void		*win_ptr;
	int			is_inside;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, image_width, image_height, "fract-ol");
	if (!mlx_ptr)
		return (1);
	if (!win_ptr)
		return (2);
	
	double	min_re = -2.0;
	double	max_re = 1.0;
	double	min_im = -1.2;
	double	max_im;
	max_im = min_im + (max_re - min_re) * image_height / image_width; // max_im
	
	
	init_complex(&factor, (max_re - min_re) / (image_width - 1), \
				(max_im - min_im) / (image_height - 1));

	y = 0;
	while (y < image_height)
	{
		x = 0;
		c.im = max_im - y * factor.im;
		while (x < image_width)
		{
			c.re = min_re + x * factor.re;
			init_complex(&z, c.re, c.im);
			iteration = 0;
			is_inside = 1;
			while (iteration < max_iteration)
			{
				if (pow(z.re, 2.0) + pow(z.im, 2.0) > pow(2.0, 2.0))
				{
					is_inside = 0;
					break ;
				}
				init_complex(&z, pow(z.re, 2.0) - pow(z.im, 2.0) + c.re, \
							2.0 * z.re * z.im +c.im);
				++iteration;
			}
			/*while ((pow(z.re, 2.0) + pow(z.im, 2.0) <= pow(2.0, 2.0)) && \
					(iteration < max_iteration))
			{
				init_complex(&z, pow(z.re, 2.0) - pow(z.im, 2.0) + c.re, \
							2.0 * z.re * z.im +c.im);
				++iteration;
				//printf("True\n");
			}
			*/
			if (is_inside)
			{
				mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0x000000);
				//black
				//printf("1");
			}
			else
			{
				mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xFFFFFF);
				//printf("0");
				//white
			}
			++x;
		}
		++y;
	}
	mlx_loop(mlx_ptr);
	return (0);
}
