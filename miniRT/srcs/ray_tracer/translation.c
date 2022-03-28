/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:59:43 by ccartman          #+#    #+#             */
/*   Updated: 2022/03/22 19:18:32 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_types.h"
#include "ray_tracer.h"

static void	translation_axis_x(t_obj *obj, int keycode);

static void	translation_axis_y(t_obj *obj, int keycode);

static void	translation_axis_z(t_obj *obj, int keycode);

void	translation(t_mrt *mrt, int keycode)
{
	t_obj	*obj;

	obj = get_selected_obj();
	if (!obj)
		return ;
	if (keycode == K_Q || keycode == K_W)
		translation_axis_x(obj, keycode);
	if (keycode == K_A || keycode == K_S)
		translation_axis_y(obj, keycode);
	if (keycode == K_Z || keycode == K_X)
		translation_axis_z(obj, keycode);
	render(mrt);
}

static void	translation_axis_x(t_obj *obj, int keycode)
{
	double	tmp;

	if (obj->intersect == intersect_plane)
		tmp = 1.;
	else
		tmp = g_translation_ratio * obj->r;
	if (keycode == K_Q)
		obj->orig[ex] -= tmp;
	else if (keycode == K_W)
		obj->orig[ex] += tmp;
}

static void	translation_axis_y(t_obj *obj, int keycode)
{
	double	tmp;

	if (obj->intersect == intersect_plane)
		tmp = 1.;
	else
		tmp = g_translation_ratio * obj->r;
	if (keycode == K_A)
		obj->orig[ey] -= tmp;
	else if (keycode == K_S)
		obj->orig[ey] += tmp;
}

static void	translation_axis_z(t_obj *obj, int keycode)
{
	double	tmp;

	if (obj->intersect == intersect_plane)
		tmp = 1.;
	else
		tmp = g_translation_ratio * obj->r;
	if (keycode == K_Z)
		obj->orig[ez] -= tmp;
	else if (keycode == K_X)
		obj->orig[ez] += tmp;
}
