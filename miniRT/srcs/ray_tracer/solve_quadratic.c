/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_quadratic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 13:36:22 by ccartman          #+#    #+#             */
/*   Updated: 2022/03/23 15:34:08 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "minirt_types.h"
#include "ray_tracer.h"
#include "libft.h"

int	solve_quadratic(double a, double b, double c, double *t)
{
	double	d;

	if (fabs(a) < g_eps)
		return (0);
	d = b * b - 4. * a * c;
	if (d - g_eps < 0.)
		return (0);
	if (fabs(d) < g_eps)
	{
		t[0] = -0.5 * b / a;
		t[1] = t[0];
	}
	else
	{
		d = sqrt(d);
		t[0] = -0.5 * (b - d) / a;
		t[1] = -0.5 * (b + d) / a;
	}
	if (t[0] > t[1])
		fswap(t, t + 1);
	return (1);
}

int	solve_quadratic_im(double a, double b, double c, double *t)
{
	double	d;
	double	q;

	if (fabs(a) < g_eps)
		return (0);
	d = b * b - 4. * a * c;
	if (d < 0.)
		return (0);
	if (fabs(d) < g_eps)
	{
		t[0] = -0.5 * b / a;
		t[1] = t[0];
	}
	else
	{
		if (b > 0.)
			q = -0.5 * (b + sqrt(d));
		else
			q = -0.5 * (b - sqrt(d));
		t[0] = q / a;
		t[1] = c / q;
	}
	if (t[0] > t[1])
		fswap(t, t + 1);
	return (1);
}
