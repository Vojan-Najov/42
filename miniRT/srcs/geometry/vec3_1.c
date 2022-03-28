/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 12:39:34 by ccartman          #+#    #+#             */
/*   Updated: 2022/03/09 12:58:45 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"

void	vec3_mult_by(t_vec3 v, double k)
{
	v[ex] *= k;
	v[ey] *= k;
	v[ez] *= k;
}

t_vec3	vec3_mult(t_vec3 v, double k)
{
	double	x;
	double	y;
	double	z;
	t_vec3	new;

	x = v[ex] * k;
	y = v[ey] * k;
	z = v[ez] * k;
	new = vec3(x, y, z);
	return (new);
}

double	vec3_dot(t_vec3 v, t_vec3 u)
{
	return (v[ex] * u[ex] + v[ey] * u[ey] + v[ez] * u[ez]);
}

void	vec3_cross_by(t_vec3 v, t_vec3 u)
{
	double	x;
	double	y;
	double	z;

	x = v[ey] * u[ez] - v[ez] * u[ey];
	y = v[ez] * u[ex] - v[ex] * u[ez];
	z = v[ex] * u[ey] - v[ey] * u[ex];
	v[ex] = x;
	v[ey] = y;
	v[ez] = z;
}

t_vec3	vec3_cross(t_vec3 v, t_vec3 u)
{
	double	x;
	double	y;
	double	z;
	t_vec3	new;

	x = v[ey] * u[ez] - v[ez] * u[ey];
	y = v[ez] * u[ex] - v[ex] * u[ez];
	z = v[ex] * u[ey] - v[ey] * u[ex];
	new = vec3(x, y, z);
	return (new);
}
