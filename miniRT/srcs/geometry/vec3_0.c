/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 12:39:24 by ccartman          #+#    #+#             */
/*   Updated: 2022/03/09 12:58:20 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "geometry.h"

t_vec3	vec3(double x, double y, double z)
{
	t_vec3	v;

	v = (t_vec3) malloc(sizeof(double) * 3);
	if (!v)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	v[ex] = x;
	v[ey] = y;
	v[ez] = z;
	return (v);
}

void	vec3_add(t_vec3 v, t_vec3 u)
{
	v[ex] += u[ex];
	v[ey] += u[ey];
	v[ez] += u[ez];
}

t_vec3	vec3_sum(t_vec3 v, t_vec3 u)
{
	double	x;
	double	y;
	double	z;
	t_vec3	new;

	x = v[ex] + u[ex];
	y = v[ey] + u[ey];
	z = v[ez] + u[ez];
	new = vec3(x, y, z);
	return (new);
}

void	vec3_sub(t_vec3 v, t_vec3 u)
{
	v[ex] -= u[ex];
	v[ey] -= u[ey];
	v[ez] -= u[ez];
}

t_vec3	vec3_diff(t_vec3 v, t_vec3 u)
{
	double	x;
	double	y;
	double	z;
	t_vec3	new;

	x = v[ex] - u[ex];
	y = v[ey] - u[ey];
	z = v[ez] - u[ez];
	new = vec3(x, y, z);
	return (new);
}
