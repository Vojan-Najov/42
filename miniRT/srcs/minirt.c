/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoan <jjoan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:34:24 by jjoan             #+#    #+#             */
/*   Updated: 2022/03/26 15:14:39 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "utils.h"
#include "minirt.h"
#include "geometry.h"
#include "ray_tracer.h"

int	main(int argc, char **argv)
{
	t_mrt	mrt;

	if (argc != 2)
		print_err(WRONG_NUM_ARGS);
	parse_file(argv[1]);
	mlx_initialization(&mrt);
	transfer_scene();
	render(&mrt);
	mlx_loop(mrt.mlx_ptr);
}
