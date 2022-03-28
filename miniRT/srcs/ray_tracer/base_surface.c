/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_surface.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 23:49:28 by ccartman          #+#    #+#             */
/*   Updated: 2022/03/18 08:28:00 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_types.h"
#include "ray_tracer.h"
#include "geometry.h"

static void	set_point(t_vec3 point, double t, t_vec3 orig, t_vec3 dir);

static void	set_normal(t_vec3 normal, t_vec3 plane_dir, int flag);

void	surface_lower_base(struct s_obj *self, t_ray *ray, double *t)
{
	set_point(self->point, t[0], ray->orig, ray->dir);
	if (self->inside)
		set_normal(self->normal, self->dir, 0);
	else
		set_normal(self->normal, self->dir, 1);
}

void	surface_upper_base(struct s_obj *self, t_ray *ray, double *t)
{
	double	up_orig[3];

	upper_base_origin(up_orig, self->orig, self->dir, self->h);
	set_point(self->point, t[0], ray->orig, ray->dir);
	if (self->inside)
		set_normal(self->normal, self->dir, 1);
	else
		set_normal(self->normal, self->dir, 0);
}

static void	set_point(t_vec3 point, double t, t_vec3 orig, t_vec3 dir)
{
	point[ex] = orig[ex] + t * dir[ex];
	point[ey] = orig[ey] + t * dir[ey];
	point[ez] = orig[ez] + t * dir[ez];
}

static void	set_normal(t_vec3 normal, t_vec3 plane_dir, int flag)
{
	if (flag)
	{
		normal[ex] = -plane_dir[ex];
		normal[ey] = -plane_dir[ey];
		normal[ez] = -plane_dir[ez];
	}
	else
	{
		normal[ex] = plane_dir[ex];
		normal[ey] = plane_dir[ey];
		normal[ez] = plane_dir[ez];
	}
}
