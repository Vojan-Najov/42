/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_module.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 15:08:33 by ccartman          #+#    #+#             */
/*   Updated: 2022/03/25 14:43:05 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <unistd.h>
#include "ray_tracer.h"

void	mlx_initialization(t_mrt *mrt)
{
	mrt->selected = 0;
	mrt->name = "miniRT";
	mrt->mlx_ptr = mlx_init();
	if (!mrt->mlx_ptr)
	{
		write(STDERR_FILENO, g_err_mlxinit, sizeof(g_err_mlxinit) - 1);
		exit(EXIT_FAILURE);
	}
	mrt->win_ptr = mlx_new_window(mrt->mlx_ptr, WIDTH, HEIGHT, mrt->name);
	if (!mrt->win_ptr)
	{
		write(STDERR_FILENO, g_err_mlxnw, sizeof(g_err_mlxnw) - 1);
		exit(EXIT_FAILURE);
	}
	mlx_clear_window(mrt->mlx_ptr, mrt->win_ptr);
	mrt->img_ptr = mlx_new_image(mrt->mlx_ptr, WIDTH, HEIGHT);
	if (!mrt->img_ptr)
	{
		write(STDERR_FILENO, g_err_mlxni, sizeof(g_err_mlxni) - 1);
		exit(EXIT_FAILURE);
	}
	mrt->addr_ptr = mlx_get_data_addr(mrt->img_ptr, &mrt->bits_per_pixel, \
										&mrt->size_line, &mrt->endian);
	define_hooks(mrt);
}

void	pixel_put(t_mrt *mrt, int x, int y, int color)
{
	char	*dst;

	dst = mrt->addr_ptr + y * mrt->size_line + x * mrt->bits_per_pixel / 8;
	*(unsigned int *) dst = color;
}
