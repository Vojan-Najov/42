/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_mtrx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 13:49:52 by ccartman          #+#    #+#             */
/*   Updated: 2022/03/09 13:12:27 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "geometry.h"

t_vec3	vec_mult_mtrx(t_vec3 v, t_mtrx44 m)
{
	t_vec3	u;
	double	x;
	double	y;
	double	z;

	x = v[ex] * m[0] + v[ey] * m[4] + v[ez] * m[8] + m[12];
	y = v[ex] * m[1] + v[ey] * m[5] + v[ez] * m[9] + m[13];
	z = v[ex] * m[2] + v[ey] * m[6] + v[ez] * m[10] + m[14];
	u = vec3(x, y, z);
	return (u);
}

t_vec3	vec_mult_proj_mtrx(t_vec3 v, t_mtrx44 m)
{
	t_vec3	u;
	double	w;

	u = vec_mult_mtrx(v, m);
	w = v[ex] * m[3] + v[ey] * m[7] + v[ez] * m[11] + m[15];
	if (fabs(w) > g_eps && fabs(w - (double) 1.) > g_eps)
	{
		u[ex] /= w;
		u[ey] /= w;
		u[ez] /= w;
	}
	return (u);
}

t_vec3	vec_dir_mult_mtrx(t_vec3 v, t_mtrx44 m)
{
	t_vec3	u;
	double	x;
	double	y;
	double	z;

	x = v[ex] * m[0] + v[ey] * m[4] + v[ez] * m[8];
	y = v[ex] * m[1] + v[ey] * m[5] + v[ez] * m[9];
	z = v[ex] * m[2] + v[ey] * m[6] + v[ez] * m[10];
	u = vec3(x, y, z);
	return (u);
}
