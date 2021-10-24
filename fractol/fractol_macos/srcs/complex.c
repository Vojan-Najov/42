/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 18:18:44 by ccartman          #+#    #+#             */
/*   Updated: 2021/10/24 18:18:47 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_complex(t_complex *c, double re, double im)
{
	c->re = re;
	c->im = im;
}

void	x2_complex(t_complex *c)
{
	double	re;
	double	im;

	re = c->re * c->re - c->im * c->im;
	im = 2.0 * c->re * c->im;
	c->re = re;
	c->im = im;
}

void	add_complex(t_complex *c, t_complex *a)
{
	c->re += a->re;
	c->im += a->im;
}

void	subtract_complex(t_complex *c, t_complex *a)
{
	c->re -= a->re;
	c->im -= a->im;
}
