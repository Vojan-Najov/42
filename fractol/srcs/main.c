/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 23:00:18 by ccartman          #+#    #+#             */
/*   Updated: 2021/10/13 23:19:39 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	void	*mlx_ptr;
	void	*win_ptr;

	(void) argc; //
	(void) argv; //
	if (argc == 1)
		// write availibale arguments
		return (0);
	mlx_ptr = mlx_init();
	if (!mlx_ptr)
		return (1);  // write message error (without errno ?)
	win_ptr = mlx_new_window(mlx_ptr, WIDTH, HEIGHT, "Fract-ol"); //change str
	if (!mlx_win)
		return (2);	// write message error (without errno?)
	if (ft_strcmp(argv[1], MANDELBROT) == 0)
		//mandelbrot
	else if (ft_strcmp(argv[1], JULIA) == 0)
		// JULIA
	else
		// write availibale arguments
		return (3);
}
