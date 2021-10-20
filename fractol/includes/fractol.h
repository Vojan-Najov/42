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

# include <stdio.h> 	//
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "mlx.h"

# define WIDTH 1350
# define HEIGHT 1080
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


static const char	HELP_MESS[] = "+++++++++++++++++++++++++++++++++++++++\n" \
								  "\n" \
								  "usage: ./fractol [Mandelbrot]\n" \
								  "       ./fractol [Julia]\n"\
								  "\n" \
								  "+++++++++++++++++++++++++++++++++++++++\n";


static const double	g_epsilon = 1e-6;

typedef struct	s_complex
{
	double	re;
	double	im;
}				t_complex;

typedef struct	s_fractol
{
	char		*name;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*addr_ptr;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	double		area[6];
	int			*colors;
	t_complex	julc;
}				t_fractol;

/* Functions for defining and modifying the area of maldebrot set */

void	define_area(t_fractol *fr);

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


/*			*/

void	define_hooks(t_fractol *fr);

/*			*/
//int		color_gray(int iter);
//int		color_red(int iter);
void	define_colors(int *colors, int flag);
void	color_red(int *colors);
void	color_gray(int *colors);
void	color_blue(int *colors);
void	color_other(int *colors);



/*			*/
void	fill_mandelbrot_set(t_fractol *fr);
void	fill_julia_set(t_fractol *fr);

/*			*/
void	completion(t_fractol *fr);

char	ft_strcmp(const char *s1, const char *s2);
#endif
