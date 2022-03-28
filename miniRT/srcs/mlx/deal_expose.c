/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_expose.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:32:46 by ccartman          #+#    #+#             */
/*   Updated: 2022/03/22 16:34:49 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "ray_tracer.h"

int	deal_expose(void *param)
{
	t_mrt	*mrt;

	mrt = (t_mrt *) param;
	mlx_put_image_to_window(mrt->mlx_ptr, mrt->win_ptr, mrt->img_ptr, 0, 0);
	return (1);
}
