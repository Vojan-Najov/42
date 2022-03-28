/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_camera.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 15:09:49 by ccartman          #+#    #+#             */
/*   Updated: 2022/03/25 17:21:28 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minirt.h"
#include "ray_tracer.h"
#include "obj_list.h"
#include "geometry.h"

static void	rotate_scene(t_mtrx44 rot);

void	rotation_camera(t_mrt *mrt, int keycode)
{
	t_mtrx44	rot;

	if (keycode == K_R)
		rot = (t_mtrx44) g_mtrx_rotx;
	if (keycode == K_T)
		rot = (t_mtrx44) g_mtrx_rotx_con;
	if (keycode == K_F)
		rot = (t_mtrx44) g_mtrx_roty;
	if (keycode == K_G)
		rot = (t_mtrx44) g_mtrx_roty_con;
	if (keycode == K_V)
		rot = (t_mtrx44) g_mtrx_rotz;
	if (keycode == K_B)
		rot = (t_mtrx44) g_mtrx_rotz_con;
	rotate_scene(rot);
	render(mrt);
}

static void	rotate_scene(t_mtrx44 rot)
{
	t_obj_lst	*objs;
	t_light		*l;
	t_vec3		tmp;

	objs = get_first_objlst();
	while (objs)
	{
		tmp = objs->obj->orig;
		objs->obj->orig = vec_mult_proj_mtrx(tmp, rot);
		free(tmp);
		if (objs->obj->intersect != intersect_sphere)
		{
			tmp = objs->obj->dir;
			objs->obj->dir = vec_dir_mult_mtrx(tmp, rot);
			vec3_normalize(objs->obj->dir);
			free(tmp);
		}
		objs = objs->next;
	}
	l = get_light();
	tmp = l->orig;
	l->orig = vec_mult_proj_mtrx(tmp, rot);
	free(tmp);
}
