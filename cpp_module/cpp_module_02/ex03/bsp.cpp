/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 20:38:07 by ccartman          #+#    #+#             */
/*   Updated: 2022/04/12 14:37:43 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static bool collinearity( Point a, Point b );

bool bsp( Point const a, Point const b, Point const c, Point const point )
{
	if (a == b || b == c || c == a)
		return false;
	Point ab = b - a;
	Point ap = point - a;
	if (collinearity(ab, ap))
		return false;
	Fixed tmp = ab.getX() * ap.getX() + ab.getY() * ap.getY();
	if (tmp < 0 || tmp > ab.getX() * ab.getX() + ab.getY() * ab.getY())
		return false;
	Point bc = c - b;
	Point bp = point - b;
	if (collinearity(bc, bp))
		return false;
	tmp = bc.getX() * bp.getX() + bc.getY() * bp.getY();
	if (tmp < 0 || tmp > bc.getX() * bc.getX() + bc.getY() * bc.getY())
		return false;
	Point ca = a - c;
	Point cp = point - c;
	if (collinearity(ca, cp))
		return false;
	tmp = ca.getX() * cp.getX() + ca.getY() * cp.getY();
	if (tmp < 0 || tmp > ca.getX() *ca.getX() + ca.getY() * ca.getY())
		return false;
	return true;
}

static bool collinearity( Point a, Point b)
{
	if (a.getX() * b.getY() - a.getY() * b.getX() == 0)
		return true;
	return false;
}
