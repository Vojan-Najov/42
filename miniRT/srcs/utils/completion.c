/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   completion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoan <jjoan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:28:26 by ccartman          #+#    #+#             */
/*   Updated: 2022/03/25 15:43:38 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include "ray_tracer.h"
#include "obj_list.h"
#include "utils.h"
#include "minirt_types.h"

void	free_obj(t_obj *obj)
{
	free(obj->orig);
	if (obj->dir)
		free(obj->dir);
	free(obj);
}

int	completion(t_mrt *mrt)
{
	t_mtrx44	lookat;

	mlx_destroy_image(mrt->mlx_ptr, mrt->img_ptr);
	mlx_destroy_window(mrt->mlx_ptr, mrt->win_ptr);
	lookat = look_at(GET_LOOKAT);
	free(lookat);
	ft_objlst_clear(free_obj);
	free_camera();
	free_ambient();
	free_light();
	exit(EXIT_SUCCESS);
	return (1);
}
