/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:28:24 by ccartman          #+#    #+#             */
/*   Updated: 2022/03/25 17:29:15 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "ray_tracer.h"

void	define_hooks(t_mrt *mrt)
{
	mlx_hook(mrt->win_ptr, DESTROY_NOTIFY, DEFAULT_MASK, completion, mrt);
	mlx_expose_hook(mrt->win_ptr, deal_expose, mrt);
	mlx_key_hook(mrt->win_ptr, deal_key, mrt);
	mlx_hook(mrt->win_ptr, BUTTON_PRESS, BUTTON_PRESS_MASK, deal_button, mrt);
}
