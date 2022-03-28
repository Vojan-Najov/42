/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 20:54:44 by ccartman          #+#    #+#             */
/*   Updated: 2022/03/22 13:05:49 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "minirt_types.h"
#include "ray_tracer.h"

void	render(t_mrt *mrt)
{
	int		i;
	int		j;
	int		color;
	t_ray	ray;

	j = -1;
	while (++j < HEIGHT)
	{
		i = -1;
		while (++i < WIDTH)
		{
			compute_ray(i, j, ray.orig, ray.dir);
			color = cast_ray(&ray);
			pixel_put(mrt, i, j, color);
		}
	}
	mlx_put_image_to_window(mrt->mlx_ptr, mrt->win_ptr, mrt->img_ptr, 0, 0);
}
