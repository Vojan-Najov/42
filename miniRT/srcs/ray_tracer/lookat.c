/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lookat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:08:57 by ccartman          #+#    #+#             */
/*   Updated: 2022/03/25 17:25:07 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "minirt_types.h"
#include "ray_tracer.h"
#include "obj_list.h"
#include "geometry.h"

static t_mtrx44	lookat_init(void);

static void		around_ratio(t_vec3 a);

static void		print_error_and_exit(const char *str);

static t_mtrx44	lookat_fill_mtrx(t_vec3 right, t_vec3 up, t_vec3 frwd, \
															t_vec3 orig);

t_mtrx44	look_at(int flag)
{
	static t_mtrx44	m;
	t_mtrx44		tmp;

	if (flag == GET_LOOKAT)
	{
		if (!m)
		{
			tmp = lookat_init();
			m = mtrx44_inverse(tmp);
			free(tmp);
		}
	}
	else if (flag == INIT_LOOKAT)
	{
		tmp = lookat_init();
		m = mtrx44_inverse(tmp);
		free(tmp);
	}
	return (m);
}

static t_mtrx44	lookat_init(void)
{
	t_camera	*cmr;
	t_vec3		frwd;
	t_vec3		up;
	t_vec3		right;
	t_vec3		tmp;

	cmr = get_camera();
	frwd = vec3(-cmr->dir[ex], -cmr->dir[ey], -cmr->dir[ez]);
	around_ratio(frwd);
	if (fabs(frwd[ex]) < g_eps && fabs(frwd[ez]) < g_eps && \
				(fabs(frwd[ey] + 1.) < g_eps || fabs(frwd[ey] - 1.) < g_eps))
		tmp = vec3(-1., 0., 0.);
	else
		tmp = vec3(0., 1., 0.);
	right = vec3_cross(tmp, frwd);
	around_ratio(right);
	free(tmp);
	up = vec3_cross(frwd, right);
	around_ratio(up);
	return (lookat_fill_mtrx(right, up, frwd, cmr->orig));
}

static void	around_ratio(t_vec3 a)
{
	if (fabs(a[ex]) < g_eps)
		a[ex] = 0.;
	if (fabs(a[ey]) < g_eps)
		a[ey] = 0.;
	if (fabs(a[ez]) < g_eps)
		a[ez] = 0.;
}

static t_mtrx44	lookat_fill_mtrx(t_vec3 right, t_vec3 up, t_vec3 frwd, \
															t_vec3 orig)
{
	t_mtrx44	m;

	m = (t_mtrx44) malloc(sizeof(double) * 16);
	if (!m)
		print_error_and_exit("malloc");
	m[0] = right[0];
	m[1] = right[1];
	m[2] = right[2];
	m[3] = 0.;
	m[4] = up[0];
	m[5] = up[1];
	m[6] = up[2];
	m[7] = 0.;
	m[8] = frwd[0];
	m[9] = frwd[1];
	m[10] = frwd[2];
	m[11] = 0.;
	m[12] = orig[0];
	m[13] = orig[1];
	m[14] = orig[2];
	m[15] = 1.;
	free(right);
	free(up);
	free(frwd);
	return (m);
}

static void	print_error_and_exit(const char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}	
