/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_ray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 20:56:58 by ccartman          #+#    #+#             */
/*   Updated: 2022/03/22 13:09:14 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "minirt_types.h"
#include "geometry.h"
#include "ray_tracer.h"
#include "obj_list.h"

void	compute_ray(int i, int j, t_vec3 orig, t_vec3 dir)
{
	t_camera	*cmr;
	double		x;
	double		y;
	double		t;

	cmr = get_camera();
	t = tan(cmr->fovhalf);
	x = (2 * ((double) i + 0.5) - g_dwidth) * t / g_dwidth;
	y = (g_dheight - 2 * ((double) j + 0.5)) * t / g_dwidth;
	orig[ex] = 0.;
	orig[ey] = 0.;
	orig[ez] = 0.;
	dir[ex] = x;
	dir[ey] = y;
	dir[ez] = -1;
	vec3_normalize(dir);
}

void	compute_shadow_ray(t_obj *cur_obj, t_vec3 orig, t_vec3 dir)
{
	t_light	*l;

	l = get_light();
	orig[ex] = cur_obj->point[ex] + g_bias * cur_obj->normal[ex];
	orig[ey] = cur_obj->point[ey] + g_bias * cur_obj->normal[ey];
	orig[ez] = cur_obj->point[ez] + g_bias * cur_obj->normal[ez];
	dir[ex] = l->orig[ex] - orig[ex];
	dir[ey] = l->orig[ey] - orig[ey];
	dir[ez] = l->orig[ez] - orig[ez];
	vec3_normalize(dir);
}
