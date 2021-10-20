/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:52:53 by ccartman          #+#    #+#             */
/*   Updated: 2021/10/16 17:51:54 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	check_args(char *arg);

static int	print_help(void);

static void	initialization(t_fractol *fr);

int	main(int argc, char **argv)
{
	t_fractol	fr;

	if (argc == 1 || !check_args(argv[1]))
		return (print_help());
	fr.colors = (int *) malloc(sizeof(int) * (MAX_ITERATIONS + 1));
	if (!fr.colors)
	{
		perror("Can't allocate memory");
		return (1);
	}
	fr.name = argv[1];
	initialization(&fr);
	if (ft_strcmp(argv[1], MANDELBROT) == 0)
		fill_mandelbrot_set(&fr);
	else if (ft_strcmp(argv[1], JULIA) == 0)
	{
		fr.julc.re = -0.74543;	
		fr.julc.im = 0.11301;
		fill_julia_set(&fr);	
	}	
	mlx_loop(fr.mlx_ptr);
}

static int	check_args(char *arg)
{
	if (ft_strcmp(arg, MANDELBROT) == 0)
		return (1);
	else if (ft_strcmp(arg, JULIA) == 0)
		return (1);
	return (0);
}

static int	print_help(void)
{
	write(STDIN_FILENO, HELP_MESS, sizeof(HELP_MESS));
	return (0);
}

static void	initialization(t_fractol *fr)
{
	fr->mlx_ptr = mlx_init();
	if (!fr->mlx_ptr)
	{
		perror("ERROR! mlx_init()");
		exit(EXIT_FAILURE);
	}
	fr->win_ptr = mlx_new_window(fr->mlx_ptr, WIDTH, HEIGHT, fr->name);
	if (!fr->win_ptr)
	{
		perror("ERROR! mlx_new_window()");
		exit(EXIT_FAILURE);
	}
	fr->img_ptr = mlx_new_image(fr->mlx_ptr, WIDTH, HEIGHT);
	if (!fr->img_ptr)
	{
		perror("ERROR! mlx_new_image()");
		exit(EXIT_FAILURE);
	}
	fr->addr_ptr = mlx_get_data_addr(fr->img_ptr, &fr->bits_per_pixel, \
									&fr->size_line, &fr->endian);
	define_area(fr);
	define_colors(fr->colors, COLOR_DEFAULT);
	define_hooks(fr);
}

char	ft_strcmp(const char *s1, const char *s2)
{
	const char unsigned	*c1;
	const char unsigned	*c2;

	c1 = (unsigned char *) s1;
	c2 = (unsigned char *) s2;
	while (*c1 || *c2)
	{
		if (*c1 != *c2)
			return (*c1 - *c2);
		++c1;
		++c2;
	}
	return (0);
}
