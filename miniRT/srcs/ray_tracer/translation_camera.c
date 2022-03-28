/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation_camera.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:47:15 by ccartman          #+#    #+#             */
/*   Updated: 2022/03/25 17:25:49 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minirt_types.h"
#include "ray_tracer.h"
#include "obj_list.h"
#include "geometry.h"

static void	move_scene(t_vec3 tmp);

void	translation_camera(t_mrt *mrt, int keycode)
{
	t_camera	*cmr;
	t_vec3		tmp;

	cmr = get_camera();
	if (keycode == K_Q)
		tmp = vec3(1., 0., 0.);
	if (keycode == K_W)
		tmp = vec3(-1., 0., 0.);
	if (keycode == K_A)
		tmp = vec3(0., 1., 0.);
	if (keycode == K_S)
		tmp = vec3(0., -1., 0.);
	if (keycode == K_Z)
		tmp = vec3(0., 0., 1.);
	if (keycode == K_X)
		tmp = vec3(0., 0., -1.);
	move_scene(tmp);
	free(tmp);
	render(mrt);
}

static void	move_scene(t_vec3 tmp)
{
	t_obj_lst	*objs;
	t_light		*l;

	l = get_light();
	vec3_add(l->orig, tmp);
	objs = get_first_objlst();
	while (objs)
	{
		vec3_add(objs->obj->orig, tmp);
		objs = objs->next;
	}
}
