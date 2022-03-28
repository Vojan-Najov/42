/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation_light.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 20:22:56 by ccartman          #+#    #+#             */
/*   Updated: 2022/03/25 21:21:04 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "minirt_types.h"
#include "ray_tracer.h"
#include "obj_list.h"
#include "geometry.h"

static void	change_theta_phi_r(int keycode, double *theta, double *phi, \
																	double *r);

void	translation_light(t_mrt *mrt, int keycode)
{
	t_light	*l;
	double	theta;
	double	phi;
	double	r;

	l = get_light();
	r = vec3_length(l->orig);
	theta = acos(l->orig[ey] / vec3_length(l->orig));
	phi = atan2(l->orig[ez], l->orig[ex]);
	change_theta_phi_r(keycode, &theta, &phi, &r);
	if (phi < 0.)
		phi += 2 * M_PI;
	l->orig[ex] = r * sin(theta) * cos(phi);
	l->orig[ey] = r * cos(theta);
	l->orig[ez] = r * sin(theta) * sin(phi);
	render(mrt);
}

static void	change_theta_phi_r(int keycode, double *theta, double *phi, \
																	double *r)
{
	if (keycode == K_Q)
	{
		*theta += (M_PI / 12.);
		if (*theta > M_PI)
			*theta = M_PI;
	}
	else if (keycode == K_W)
	{
		*theta -= (M_PI / 12.);
		if (*theta < 0.)
			*theta = 0.;
	}
	else if (keycode == K_A)
		*phi -= (M_PI / 12.);
	else if (keycode == K_S)
		*phi += (M_PI / 12.);
	else if (keycode == K_Z)
		*r *= 0.9;
	else if (keycode == K_X)
		*r *= 1.1;
}
