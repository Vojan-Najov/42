/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 15:57:30 by ccartman          #+#    #+#             */
/*   Updated: 2021/10/16 18:19:52 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	define_hooks(t_fractol *fr)
{
	mlx_key_hook(fr->win_ptr, deal_key, fr);
		
}

int		deal_key(int keycode, t_fractol *fr)
{
	if (keycode == ESC)
		completion(fr);
	else if (keycode == ARROW_LEFT)
	{
		add_area(fr, -0.05, 0.);
	}
	else if (keycode == ARROW_RIGHT)
	{
		add_area(fr, 0.05, 0.);
	}
	else if (keycode == ARROW_UP)
	{
		add_area(fr, 0., 0.05);
	}
	else if (keycode == ARROW_DOWN)
	{
		add_area(fr, 0., -0.05);
	}
}

int		deal_mouse(int keycode, int x, int y, t_fractol fr)
{
	if (keycode == WHEEL_UP)
	{

	}
	else if (keycode == WHEEL_DOWN)
	{

	}
	else if (keycode == MOUSE_LEFT_KEY)
	{

	}
	else if (keycode == MOUSE_RIGHT_KEY)
	{

	}
}
