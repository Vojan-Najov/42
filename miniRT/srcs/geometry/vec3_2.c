/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 12:39:44 by ccartman          #+#    #+#             */
/*   Updated: 2022/03/24 22:30:31 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include "geometry.h"

int	vec3_collinearity(t_vec3 v, t_vec3 u)
{
	t_vec3	w;
	int		ret;

	ret = 0;
	w = vec3_cross(v, u);
	if (fabs(w[ex]) < g_eps && fabs(w[ey]) < g_eps && fabs(w[ez]) < g_eps)
		ret = 1;
	free(w);
	return (ret);
}

double	vec3_norm(t_vec3 v)
{
	return (v[ex] * v[ex] + v[ey] * v[ey] + v[ez] * v[ez]);
}

double	vec3_length(t_vec3 v)
{
	double	x;
	double	y;
	double	z;

	x = v[ex];
	y = v[ey];
	z = v[ez];
	return (sqrt(x * x + y * y + z * z));
}

void	vec3_normalize(t_vec3 v)
{
	double	len;
	double	factor;

	len = vec3_length(v);
	if (len)
	{
		factor = (double) 1. / len;
		v[ex] *= factor;
		v[ey] *= factor;
		v[ez] *= factor;
	}
}

void	vec3_diff_vec3(t_vec3 v, t_vec3 u, t_vec3 w)
{
	w[0] = v[0] - u[0];
	w[1] = v[1] - u[1];
	w[2] = v[2] - u[2];
}
