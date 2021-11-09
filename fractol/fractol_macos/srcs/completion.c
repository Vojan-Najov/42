/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   completion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 18:18:13 by ccartman          #+#    #+#             */
/*   Updated: 2021/10/24 18:18:17 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	completion(t_fractol *fr)
{
	mlx_destroy_image(fr->mlx_ptr, fr->img_ptr);
	mlx_destroy_window(fr->mlx_ptr, fr->win_ptr);
	free(fr->colors);
	exit(0);
	return (1);
}
