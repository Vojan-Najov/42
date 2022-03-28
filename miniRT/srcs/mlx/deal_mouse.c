/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_mouse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:11:05 by ccartman          #+#    #+#             */
/*   Updated: 2022/03/25 17:28:54 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "ray_tracer.h"

int	deal_button(int button, int x, int y, void *param)
{
	t_mrt	*mrt;

	mrt = (t_mrt *) param;
	if (button == B_LEFT || button == B_RIGHT)
	{
		select_obj(x, y);
		mrt->selected = OBJ_SELECTED;
	}
	return (1);
}
