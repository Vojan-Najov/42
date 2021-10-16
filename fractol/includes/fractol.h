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
# define ARROW_LEFT 123
# define ARROW_RIGHT 124
# define ARROW_UP 126
# define ARROW_DOWN 125

static const char	HELP_MESS[] = "+++++++++++++++++++++++++++++++++++++++\n" \
								  "\n" \
								  "usage: ./fractol [Mandelbrot]\n" \
								  "       ./fractol [Julia]\n"\
								  "\n" \
								  "+++++++++++++++++++++++++++++++++++++++\n";


static const double	g_epsilon = 1e-6;

typedef struct	s_fractol
{
	char	*name;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*addr_ptr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	double	area[6];
}				t_fractol;

typedef struct	s_complex
{
	double	re;
	double	im;
}				t_complex;

/* Functions for defining and modifying the area of maldebrot set */

void	define_area(t_fractol *fr);

void	add_area(t_fractol *fr, double dx, double dy);

void	mul_area(t_fractol *fr, double dx, double dy);

#endif
