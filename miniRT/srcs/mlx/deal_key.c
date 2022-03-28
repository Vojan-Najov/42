/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:26:04 by ccartman          #+#    #+#             */
/*   Updated: 2022/03/25 22:43:14 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "ray_tracer.h"
#include <stdio.h>

static void	deal_key_obj(t_mrt *mrt, int keycode);

static void	deal_key_cmr(t_mrt *mrt, int keycode);

static void	deal_key_light(t_mrt *mrt, int keycode);

int	deal_key(int keycode, void *param)
{
	t_mrt	*mrt;

	mrt = (t_mrt *) param;
	if (keycode == K_ESC)
		completion(mrt);
	else if (keycode == K_H)
		get_help();
	else if (keycode == K_C)
	{
		mrt->selected = CMR_SELECTED;
		printf("You have selected camera\n");
	}
	else if (keycode == K_L)
	{
		mrt->selected = LGHT_SELECTED;
		printf("You have selected light\n");
	}
	else if (mrt->selected == OBJ_SELECTED)
		deal_key_obj(mrt, keycode);
	else if (mrt->selected == CMR_SELECTED)
		deal_key_cmr(mrt, keycode);
	else if (mrt->selected == LGHT_SELECTED)
		deal_key_light(mrt, keycode);
	return (1);
}

static void	deal_key_obj(t_mrt *mrt, int keycode)
{
	if (keycode == K_PLUS1 || keycode == K_PLUS2 || \
						keycode == K_MINUS1 || keycode == K_MINUS2)
		resize_radius(mrt, keycode);
	else if (keycode == K_SQBR2 || keycode == K_SQBR1)
		resize_height(mrt, keycode);
	else if (keycode == K_Q || keycode == K_W || keycode == K_A || \
						keycode == K_S || keycode == K_Z || keycode == K_X)
		translation(mrt, keycode);
	else if (keycode == K_R || keycode == K_T || keycode == K_F || \
						keycode == K_G || keycode == K_V || keycode == K_B)
		rotation(mrt, keycode);
}

static void	deal_key_cmr(t_mrt *mrt, int keycode)
{
	if (keycode == K_Q || keycode == K_W || keycode == K_A || \
				keycode == K_S || keycode == K_Z || keycode == K_X)
		translation_camera(mrt, keycode);
	else if (keycode == K_R || keycode == K_T || keycode == K_F || \
				keycode == K_G || keycode == K_V || keycode == K_B)
		rotation_camera(mrt, keycode);
}

static void	deal_key_light(t_mrt *mrt, int keycode)
{
	if (keycode == K_Q || keycode == K_W || keycode == K_A || \
				keycode == K_S || keycode == K_Z || keycode == K_X)
		translation_light(mrt, keycode);
}
