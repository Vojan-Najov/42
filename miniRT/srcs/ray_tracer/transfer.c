/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transfer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:06:59 by ccartman          #+#    #+#             */
/*   Updated: 2022/03/25 16:28:29 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minirt_types.h"
#include "geometry.h"
#include "obj_list.h"
#include "ray_tracer.h"

static void	transfer_camera(void);

static void	transfer_light(t_mtrx44 lookat);

static void	transfer_objects(t_mtrx44 lookat);

void	transfer_scene(void)
{
	t_mtrx44	lookat;

	lookat = look_at(GET_LOOKAT);
	transfer_camera();
	transfer_light(lookat);
	transfer_objects(lookat);
}

static void	transfer_camera(void)
{
	t_camera	*cmr;

	cmr = get_camera();
	cmr->orig[ex] = 0.;
	cmr->orig[ey] = 0.;
	cmr->orig[ez] = 0.;
	cmr->dir[ex] = 0.;
	cmr->dir[ey] = 0.;
	cmr->dir[ez] = -1.;
}

static void	transfer_light(t_mtrx44 lookat)
{
	t_light	*l;
	t_vec3	tmp;

	l = get_light();
	tmp = l->orig;
	l->orig = vec_mult_proj_mtrx(tmp, lookat);
	free(tmp);
}

static void	transfer_objects(t_mtrx44 lookat)
{
	t_obj_lst	*objs;
	t_obj		*obj;
	t_vec3		tmp;

	objs = get_first_objlst();
	while (objs)
	{
		obj = objs->obj;
		tmp = obj->orig;
		obj->orig = vec_mult_proj_mtrx(tmp, lookat);
		free(tmp);
		if (obj->intersect != intersect_sphere)
		{
			tmp = obj->dir;
			obj->dir = vec_dir_mult_mtrx(tmp, lookat);
			vec3_normalize(obj->dir);
			free(tmp);
		}
		objs = objs->next;
	}
}
