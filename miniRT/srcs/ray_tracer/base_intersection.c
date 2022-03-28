/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_intersection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 19:18:22 by ccartman          #+#    #+#             */
/*   Updated: 2022/03/17 05:20:34 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_types.h"
#include "geometry.h"
#include "ray_tracer.h"
#include <math.h>

int	intersect_lower_base(struct s_obj *self, t_ray *ray, double *t)
{
	double	l[3];
	double	d;
	double	t0;
	double	tmp[3];

	d = vec3_dot(ray->dir, self->dir);
	if (fabs(d) > g_eps)
	{
		vec3_diff_vec3(self->orig, ray->orig, l);
		t0 = vec3_dot(l, self->dir) / d;
		if (t0 < 0.)
			return (0);
		t[0] = t0;
		tmp[ex] = ray->orig[ex] + ray->dir[ex] * t0 - self->orig[ex];
		tmp[ey] = ray->orig[ey] + ray->dir[ey] * t0 - self->orig[ey];
		tmp[ez] = ray->orig[ez] + ray->dir[ez] * t0 - self->orig[ez];
		if (vec3_norm(tmp) < self->r2)
			return (1);
	}
	return (0);
}

int	intersect_upper_base(struct s_obj *self, t_ray *ray, double *t)
{
	double	l[3];
	double	orig[3];
	double	d;
	double	t0;
	double	tmp[3];

	d = vec3_dot(ray->dir, self->dir);
	if (fabs(d) > g_eps)
	{
		upper_base_origin(orig, self->orig, self->dir, self->h);
		vec3_diff_vec3(orig, ray->orig, l);
		t0 = vec3_dot(l, self->dir) / d;
		if (t0 < 0.)
			return (0);
		t[0] = t0;
		tmp[ex] = ray->orig[ex] + ray->dir[ex] * t0 - orig[ex];
		tmp[ey] = ray->orig[ey] + ray->dir[ey] * t0 - orig[ey];
		tmp[ez] = ray->orig[ez] + ray->dir[ez] * t0 - orig[ez];
		if (vec3_norm(tmp) < self->r2)
			return (1);
	}
	return (0);
}

void	upper_base_origin(t_vec3 orig, t_vec3 point, t_vec3 n, double h)
{
	orig[ex] = point[ex] + h * n[ex];
	orig[ey] = point[ey] + h * n[ey];
	orig[ez] = point[ez] + h * n[ez];
}
