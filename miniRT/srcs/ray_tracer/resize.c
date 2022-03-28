/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:39:21 by ccartman          #+#    #+#             */
/*   Updated: 2022/03/22 17:51:19 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_types.h"
#include "ray_tracer.h"

void	resize_radius(t_mrt *mrt, int keycode)
{
	t_obj	*obj;

	obj = get_selected_obj();
	if (!obj || obj->intersect == intersect_plane)
		return ;
	if (keycode == K_PLUS1 || keycode == K_PLUS2)
	{
		obj->r *= g_resize_ratio_plus;
		obj->r2 = obj->r * obj->r;
	}
	if (keycode == K_MINUS1 || keycode == K_MINUS2)
	{
		obj->r *= g_resize_ratio_minus;
		obj->r2 = obj->r * obj->r;
	}
	render(mrt);
}

void	resize_height(t_mrt *mrt, int keycode)
{
	t_obj	*obj;

	obj = get_selected_obj();
	if (!obj || obj->intersect != intersect_cylinder)
		return ;
	if (keycode == K_SQBR2)
	{
		obj->h *= g_resize_ratio_plus;
	}
	if (keycode == K_SQBR1)
	{
		obj->h *= g_resize_ratio_minus;
	}
	render(mrt);
}
