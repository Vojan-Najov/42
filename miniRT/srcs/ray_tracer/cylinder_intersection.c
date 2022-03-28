/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_intersection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 20:46:51 by ccartman          #+#    #+#             */
/*   Updated: 2022/03/23 15:42:08 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_types.h"
#include "geometry.h"
#include "ray_tracer.h"
#include <math.h>
#include "libft.h"

static int	compute_ratio(struct s_obj *self, t_ray *ray, double *t, \
																double *m);

static int	intersect_cylinder_inside(struct s_obj *self, t_ray *ray, \
											double *t, double *m);

static int	intersect_cylinder_outside(struct s_obj *self, t_ray *ray, \
											double *t, double *m);

int	intersect_cylinder(struct s_obj *self, t_ray *ray, double *t)
{
	double	tmp[3];
	double	d;

	if (!compute_ratio(self, ray, t, t + 2))
		return (0);
	if (t[1] < 0.)
	{
		vec3_diff_vec3(ray->orig, self->orig, tmp);
		d = vec3_dot(tmp, self->dir);
		if (d < 0.)
		{
			t[2] = d;
			return (intersect_lower_base(self, ray, t));
		}
		else if (d > self->h)
		{
			t[2] = d;
			return (intersect_upper_base(self, ray, t));
		}
		else
			return (intersect_cylinder_inside(self, ray, t, t + 2));
	}
	return (intersect_cylinder_outside(self, ray, t, t + 2));
}

static int	intersect_cylinder_inside(struct s_obj *self, t_ray *ray, \
											double *t, double *m)
{
	self->inside = 1;
	if (m[0] < 0.)
		return (intersect_lower_base(self, ray, t));
	else if (m[0] > self->h)
		return (intersect_upper_base(self, ray, t));
	return (1);
}

static int	intersect_cylinder_outside(struct s_obj *self, t_ray *ray, \
											double *t, double *m)
{
	if (m[0] < 0.)
	{
		if (m[1] < 0.)
			return (0);
		return (intersect_lower_base(self, ray, t));
	}
	else if (m[0] > self->h)
	{
		if (m[1] > self->h)
			return (0);
		return (intersect_upper_base(self, ray, t));
	}
	return (1);
}

static int	compute_ratio(struct s_obj *self, t_ray *ray, double *t, double *m)
{
	double	l[3];
	double	ratio[3];
	double	d_v;
	double	v_oc;

	vec3_diff_vec3(ray->orig, self->orig, l);
	d_v = vec3_dot(ray->dir, self->dir);
	v_oc = vec3_dot(self->dir, l);
	ratio[0] = vec3_norm(ray->dir) - pow(d_v, 2.);
	ratio[1] = 2. * (vec3_dot(ray->dir, l) - d_v * v_oc);
	ratio[2] = vec3_norm(l) - pow(v_oc, 2.) - self->r2;
	if (!solve_quadratic_im(ratio[0], ratio[1], ratio[2], t))
		return (0);
	if (t[0] < 0.)
	{
		fswap(t, t + 1);
		if (t[0] < 0.)
			return (0);
	}
	m[0] = v_oc + d_v * t[0];
	m[1] = v_oc + d_v * t[1];
	return (1);
}
