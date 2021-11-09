/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 18:21:34 by ccartman          #+#    #+#             */
/*   Updated: 2021/10/24 18:21:36 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	pixel_put(t_fractol *fr, int x, int y, int iter)
{
	int		color;
	char	*dst;

	color = fr->colors[iter];
	dst = fr->addr_ptr + y * fr->size_line + x * fr->bits_per_pixel / 8;
	*(unsigned int *) dst = color;
}
