/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:30:02 by ccartman          #+#    #+#             */
/*   Updated: 2022/03/21 14:16:29 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_types.h"
#include "geometry.h"
#include "ray_tracer.h"
#include "libft.h"

static void	set_point(t_vec3 point, double t, t_vec3 orig, t_vec3 dir);

static void	set_normal(t_vec3 normal, double *t, t_vec3 point, t_vec3 orig);

int	intersect_sphere(struct s_obj *self, t_ray *ray, double *t)
{
	double	a;
	double	b;
	double	c;
	double	l[3];

	vec3_diff_vec3(ray->orig, self->orig, l);
	a = vec3_norm(ray->dir);
	b = 2. * vec3_dot(ray->dir, l);
	c = vec3_norm(l) - self->r2;
	if (!solve_quadratic(a, b, c, t))
		return (0);
	if (t[0] - g_eps < 0.)
	{
		fswap(t, t + 1);
		if (t[0] - g_eps < 0.)
			return (0);
	}
	return (1);
}

void	surface_sphere(struct s_obj *self, t_ray *ray, double *t)
{
	set_point(self->point, t[0], ray->orig, ray->dir);
	set_normal(self->normal, t, self->point, self->orig);
}

static void	set_point(t_vec3 point, double t, t_vec3 orig, t_vec3 dir)
{
	point[ex] = orig[ex] + t * dir[ex];
	point[ey] = orig[ey] + t * dir[ey];
	point[ez] = orig[ez] + t * dir[ez];
}

static void	set_normal(t_vec3 normal, double *t, t_vec3 point, t_vec3 orig)
{
	if (t[1] - g_eps < 0.)
	{
		normal[ex] = orig[ex] - point[ex];
		normal[ey] = orig[ey] - point[ey];
		normal[ez] = orig[ez] - point[ez];
	}
	else
	{
		normal[ex] = point[ex] - orig[ex];
		normal[ey] = point[ey] - orig[ey];
		normal[ez] = point[ez] - orig[ez];
	}
	vec3_normalize(normal);
}
