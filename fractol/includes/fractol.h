#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "mlx.h"

# define WIDTH 1350
# define HEIGHT 1080
# define MAX_ITERATIONS 50
# define MANDELBROT "Mandelbrot"
# define JULIA "Julia"
# define RE_MIN 0
# define RE_MAX 1
# define IM_MIN 2
# define IM_MAX 3
# define RE_FACTOR 4
# define IM_FACTOR 5
# define ESC 53

static const double	g_epsilon = 1e-6;

typedef struct	s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*addr_ptr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	double	area[6];
}				t_mlx;

typedef struct	s_complex
{
	double	re;
	double	im;
}				t_complex;

#endif
