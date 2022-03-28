/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 19:24:20 by ccartman          #+#    #+#             */
/*   Updated: 2022/03/24 22:25:21 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include "minirt_types.h"
#include "ray_tracer.h"
#include "geometry.h"

static void	rotation_cl(t_obj *obj, t_mtrx44 rot);

static void	rotation_pl(t_obj *obj, t_mtrx44 rot);

void	rotation(t_mrt *mrt, int keycode)
{
	t_obj		*obj;
	t_mtrx44	rot;

	obj = get_selected_obj();
	if (!obj || obj->intersect == intersect_sphere)
		return ;
	if (keycode == K_R)
		rot = (double *) g_mtrx_rotx;
	if (keycode == K_T)
		rot = (double *) g_mtrx_rotx_con;
	if (keycode == K_F)
		rot = (double *) g_mtrx_roty;
	if (keycode == K_G)
		rot = (double *) g_mtrx_roty_con;
	if (keycode == K_V)
		rot = (double *) g_mtrx_rotz;
	if (keycode == K_B)
		rot = (double *) g_mtrx_rotz_con;
	if (obj->intersect == intersect_cylinder)
		rotation_cl(obj, rot);
	else if (obj->intersect == intersect_plane)
		rotation_pl(obj, rot);
	render(mrt);
}

static void	rotation_cl(t_obj *obj, t_mtrx44 rot)
{
	double	old_center[3];
	double	new_center[3];
	double	delta[3];
	double	*tmp;

	old_center[ex] = obj->orig[ex] + 0.5 * obj->h * obj->dir[ex];
	old_center[ey] = obj->orig[ey] + 0.5 * obj->h * obj->dir[ey];
	old_center[ez] = obj->orig[ez] + 0.5 * obj->h * obj->dir[ez];
	tmp = obj->dir;
	obj->dir = vec_dir_mult_mtrx(tmp, rot);
	free(tmp);
	vec3_normalize(obj->dir);
	new_center[ex] = obj->orig[ex] + 0.5 * obj->h * obj->dir[ex];
	new_center[ey] = obj->orig[ey] + 0.5 * obj->h * obj->dir[ey];
	new_center[ez] = obj->orig[ez] + 0.5 * obj->h * obj->dir[ez];
	vec3_diff_vec3(old_center, new_center, delta);
	vec3_add(obj->orig, delta);
}

static void	rotation_pl(t_obj *obj, t_mtrx44 rot)
{
	double	*tmp;

	tmp = obj->dir;
	obj->dir = vec_dir_mult_mtrx(tmp, rot);
	vec3_normalize(obj->dir);
	free(tmp);
}
