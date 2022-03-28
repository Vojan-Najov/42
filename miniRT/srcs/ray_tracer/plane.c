/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 12:08:36 by ccartman          #+#    #+#             */
/*   Updated: 2022/03/22 12:45:28 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_types.h"
#include "ray_tracer.h"
#include "geometry.h"
#include <math.h>

static void	set_point(t_vec3 point, double t, t_vec3 orig, t_vec3 dir);

static void	set_normal(t_vec3 normal, t_vec3 ray_dir, t_vec3 plane_dir);

int	intersect_plane(struct s_obj *self, t_ray *ray, double *t)
{
	double	l[3];
	double	d;

	d = vec3_dot(self->dir, ray->dir);
	if (fabs(d) > g_eps)
	{
		vec3_diff_vec3(self->orig, ray->orig, l);
		t[0] = vec3_dot(l, self->dir) / d;
		if (t[0] - g_eps > 0.)
			return (1);
	}
	return (0);
}

void	surface_plane(struct s_obj *self, t_ray *ray, double *t)
{
	set_point(self->point, t[0], ray->orig, ray->dir);
	set_normal(self->normal, ray->dir, self->dir);
}

static void	set_point(t_vec3 point, double t, t_vec3 orig, t_vec3 dir)
{
	point[ex] = orig[ex] + t * dir[ex];
	point[ey] = orig[ey] + t * dir[ey];
	point[ez] = orig[ez] + t * dir[ez];
}

static void	set_normal(t_vec3 normal, t_vec3 ray_dir, t_vec3 plane_dir)
{
	if (vec3_dot(ray_dir, plane_dir) < 0.)
	{
		normal[ex] = plane_dir[ex];
		normal[ey] = plane_dir[ey];
		normal[ez] = plane_dir[ez];
	}
	else
	{
		normal[ex] = -plane_dir[ex];
		normal[ey] = -plane_dir[ey];
		normal[ez] = -plane_dir[ez];
	}
}
