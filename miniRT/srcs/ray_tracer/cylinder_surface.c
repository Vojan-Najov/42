/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_surface.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 22:27:59 by ccartman          #+#    #+#             */
/*   Updated: 2022/03/18 08:28:03 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_types.h"
#include "geometry.h"
#include "ray_tracer.h"
#include <math.h>

static void	set_point(t_vec3 point, t_vec3 orig, t_vec3 dir, double t);

static void	set_normal_inside(struct s_obj *self, t_vec3 normal, \
													t_vec3 point, double m);

static void	set_normal_outside(struct s_obj *self, t_vec3 normal, \
													t_vec3 point, double m);

void	surface_cylinder(struct s_obj *self, t_ray *ray, double *t)
{
	if (self->inside)
	{
		if (t[2] < 0.)
			surface_lower_base(self, ray, t);
		else if (t[2] > self->h)
			surface_upper_base(self, ray, t);
		else
		{
			set_point(self->point, ray->orig, ray->dir, t[0]);
			set_normal_inside(self, self->normal, self->point, t[2]);
		}
	}
	else
	{
		if (t[2] < 0.)
			surface_lower_base(self, ray, t);
		else if (t[2] > self->h)
			surface_upper_base(self, ray, t);
		else
		{
			set_point(self->point, ray->orig, ray->dir, t[0]);
			set_normal_outside(self, self->normal, self->point, t[2]);
		}	
	}
}

static void	set_point(t_vec3 point, t_vec3 orig, t_vec3 dir, double t)
{
	point[ex] = orig[ex] + t * dir[ex];
	point[ey] = orig[ey] + t * dir[ey];
	point[ez] = orig[ez] + t * dir[ez];
}

static void	set_normal_inside(struct s_obj *self, t_vec3 normal, \
													t_vec3 point, double m)
{
	normal[ex] = m * self->dir[ex] - point[ex] + self->orig[ex];
	normal[ey] = m * self->dir[ey] - point[ey] + self->orig[ey];
	normal[ez] = m * self->dir[ez] - point[ez] + self->orig[ez];
	vec3_normalize(normal);
}	

static void	set_normal_outside(struct s_obj *self, t_vec3 normal, \
													t_vec3 point, double m)
{
	normal[ex] = point[ex] - self->orig[ex] - m * self->dir[ex];
	normal[ey] = point[ey] - self->orig[ey] - m * self->dir[ey];
	normal[ez] = point[ez] - self->orig[ez] - m * self->dir[ez];
	vec3_normalize(normal);
}	
