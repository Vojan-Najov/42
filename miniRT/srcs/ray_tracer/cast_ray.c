/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 21:23:22 by ccartman          #+#    #+#             */
/*   Updated: 2022/03/24 22:24:12 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "minirt_types.h"
#include "obj_list.h"
#include "geometry.h"
#include "ray_tracer.h"

static int		compute_shadow(t_obj *cur_obj, t_ray *ray, double cos_norm_dir);

static int		trace_shadow(t_ray *ray);

static double	get_distance_to_light(t_vec3 ray_orig);

int	cast_ray(t_ray *ray)
{
	t_obj	*hit_obj;
	int		color;
	t_ray	shadow_ray;
	double	cos_norm_dir;

	if (trace(ray, &hit_obj))
	{
		hit_obj->surface(hit_obj, ray, hit_obj->t);
		compute_shadow_ray(hit_obj, shadow_ray.orig, shadow_ray.dir);
		cos_norm_dir = vec3_dot(hit_obj->normal, shadow_ray.dir);
		color = compute_shadow(hit_obj, &shadow_ray, cos_norm_dir);
		return (color);
	}
	return (0x0);
}

int	trace(t_ray *ray, t_obj **hit_obj)
{
	t_obj_lst	*objs;
	t_obj		*obj;
	double		*t;
	double		t_near;

	objs = get_first_objlst();
	t_near = g_inf;
	*hit_obj = NULL;
	while (objs)
	{
		obj = objs->obj;
		t = obj->t;
		if (obj->intersect(obj, ray, t))
		{
			if (t[0] < t_near)
			{
				*hit_obj = obj;
				t_near = t[0];
			}
		}
		objs = objs->next;
	}
	return (*hit_obj != NULL);
}

static int	compute_shadow(t_obj *cur_obj, t_ray *ray, double cos_norm_dir)
{
	t_ambient	*amb;
	t_light		*l;
	int			r;
	int			g;
	int			b;

	amb = get_ambient();
	l = get_light();
	r = (int)(cur_obj->albedo[er] * amb->ratio * amb->color[er]);
	g = (int)(cur_obj->albedo[eg] * amb->ratio * amb->color[eg]);
	b = (int)(cur_obj->albedo[eb] * amb->ratio * amb->color[eb]);
	if (cos_norm_dir < 0.)
		cos_norm_dir = 0.;
	if (trace_shadow(ray))
	{
		r += (int)(cur_obj->albedo[er] * cos_norm_dir * l->ratio * g_light);
		g += (int)(cur_obj->albedo[eg] * cos_norm_dir * l->ratio * g_light);
		b += (int)(cur_obj->albedo[eb] * cos_norm_dir * l->ratio * g_light);
	}
	return (get_color(r, g, b));
}

static int	trace_shadow(t_ray *ray)
{
	t_obj_lst	*objs;
	t_obj		*obj;
	double		dist;
	double		tmp[3];
	double		*t;

	objs = get_first_objlst();
	dist = get_distance_to_light(ray->orig);
	while (objs)
	{
		obj = objs->obj;
		t = obj->t;
		if (obj->intersect(obj, ray, obj->t))
		{
			tmp[ex] = t[0] * ray->dir[ex];
			tmp[ey] = t[0] * ray->dir[ey];
			tmp[ez] = t[0] * ray->dir[ez];
			if (vec3_norm(tmp) < dist)
				return (0);
		}
		objs = objs->next;
	}
	return (1);
}

static double	get_distance_to_light(t_vec3 ray_orig)
{
	t_light	*l;
	double	tmp[3];
	double	dist;

	l = get_light();
	tmp[ex] = l->orig[ex] - ray_orig[ex];
	tmp[ey] = l->orig[ey] - ray_orig[ey];
	tmp[ez] = l->orig[ez] - ray_orig[ez];
	dist = vec3_norm(tmp);
	return (0.9999 * dist);
}
