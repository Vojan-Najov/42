/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 15:05:04 by ccartman          #+#    #+#             */
/*   Updated: 2021/10/16 18:19:54 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "mlx.h"

# define WIDTH 500//1350
# define HEIGHT 500//1080
# define MAX_ITERATIONS 100
# define MANDELBROT "Mandelbrot"
# define JULIA "Julia"
# define RE_MIN 0
# define RE_MAX 1
# define IM_MIN 2
# define IM_MAX 3
# define RE_FACTOR 4
# define IM_FACTOR 5
# define ESC 65307		//53
# define SPACE 32
# define ARROW_LEFT 65361	//123
# define ARROW_RIGHT 65363		//124
# define ARROW_UP 65362			//126
# define ARROW_DOWN 65364			//125
# define Q_KEY 113
# define MOUSE_LEFT_BUTTON 1
# define MOUSE_RIGHT_BUTTON 3
# define MOUSE_WHEEL_BUTTON 2
# define MOUSE_WHEEL_UP 4
# define MOUSE_WHEEL_DOWN 5
# define COLOR_DEFAULT 0
# define COLOR_NEXT 1
# define COLOR_RED 0
# define COLOR_GRAY 1
# define COLOR_BLUE 2
# define BUTTON_RELEASE 5
# define MOTION_NOTIFY 6
# define DEFAULT_MASK 0

static const char	g_arg_err[] = "Incorrect arguments.\n";

static const char	g_help_mess[] = "\n" \
								  	"usage: ./fractol [Mandelbrot]\n" \
								  	"       ./fractol [Julia]\n" \
								  	"       ./fractol [Julia] [re] [im]\n" \
									"where [re] is the real part,\n" \
									"and   [im] is the imaginary part\n" \
									"of a complex number for julia set.\n" \
									"\nControl:\n" \
									"Left Mouse button alligns the image with"\
									" the cursor.\n" \
									"Mouse wheel for zoom/dezoom image.\n" \
									"Right mouse button pressed together with "\
									"the movement changes the julia set.\n" \
									"Arrows change the position of the image.\n" \
									"Use ESC for exit.\n" \
								  	"\n";

typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

typedef struct s_fractol
{
	char		*name;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*addr_ptr;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	int			*colors;
	double		radius;
	t_complex	julc;
	double		area[6];
}	t_fractol;

/* Functions for defining and modifying the area of maldebrot set */

void	define_area(t_fractol *fr);

void	define_julia_area(t_fractol *fr);

void	add_area(t_fractol *fr, double dx, double dy);

void	mult_area(t_fractol *fr, double dx, double dy);

/* 
*  Functions for working with comlex numbers.
*  init_complex -- initialization of complex number.
*  x2_complex -- raising to the second power of a complex number.
*  add_complex -- add to the first number the second.
*/

void	init_complex(t_complex *c, double re, double im);
void	x2_complex(t_complex *c);
void	add_complex(t_complex *c, t_complex *a);

/*	
* install event handlers: mouse movement, keyboard keystroke,
* pressing different mouse buttons.
*/

void	define_hooks(t_fractol *fr);

/*
*  create an array of colors.
*  gray or red, or blue, or multicolored.
*  pixel_put paints a pixel in a certain color from the colors array,
*  depending on the number of iterations.
*/

void	define_colors(int *colors, int flag);
void	color_red(int *colors);
void	color_gray(int *colors);
void	color_blue(int *colors);
void	color_other(int *colors);
void	pixel_put(t_fractol *fr, int x, int y, int iter);

/*
*  Output an image of the Mandelbrot set, the Julia set,
*  the Burning Ship set.
*/

void	init_julia_set(t_fractol *fr, int argc, char **argv);
void	draw_fractal(t_fractol *fr);
void	fill_mandelbrot_set(t_fractol *fr);
void	fill_julia_set(t_fractol *fr);

/*
*  completion the program when pressing Esc
*  or the cross of the graphic window.
*/

void	completion(t_fractol *fr);

/*
*  utilitarian functions.
*/

int		print_help(void);
char	ft_strcmp(const char *s1, const char *s2);
int		ft_isdigit(int c);
int		check_float(const char *str);
double	ft_atof(const char *str);

#endif
