/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_obj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:36:24 by ccartman          #+#    #+#             */
/*   Updated: 2022/03/24 22:27:56 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "minirt_types.h"
#include "ray_tracer.h"
#include <stdio.h>
#include "geometry.h"

static void	print_message(t_obj *obj);

static t_obj	**get_selected_obj_address(void)
{
	static t_obj	*ptr;

	return (&ptr);
}

t_obj	*get_selected_obj(void)
{
	t_obj	**ptr;

	ptr = get_selected_obj_address();
	return (*ptr);
}

void	select_obj(int x, int y)
{
	t_obj	**obj;
	t_ray	ray;

	obj = get_selected_obj_address();
	*obj = NULL;
	compute_ray(x, y, ray.orig, ray.dir);
	trace(&ray, obj);
	if (!(*obj))
		return ;
	print_message(*obj);
}

static void	print_message(t_obj *obj)
{
	if (obj->intersect == intersect_sphere)
	{
		printf("You have selected sphere with the coordinates of the center ");
		vec3_print(obj->orig);
		printf("and radius %6.3lf\n", obj->r);
	}	
	else if (obj->intersect == intersect_cylinder)
	{
		printf("You have selected cylinder with the coordinates of the lower" \
																	"base ");
		vec3_print(obj->orig);
		printf(", radius %6.3lf and height %6.3lf\n", obj->r, obj->h);
	}
	else if (obj->intersect == intersect_plane)
	{
		printf("You have selected plane\n");
	}
}
