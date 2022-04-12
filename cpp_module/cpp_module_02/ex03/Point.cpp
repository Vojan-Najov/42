/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 20:01:53 by ccartman          #+#    #+#             */
/*   Updated: 2022/04/12 15:57:02 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point( void ) : x(), y() {}

Point::Point( float const f1, float const f2) : x(f1), y(f2) {}

Point::Point( Point const & point ) : x(point.x), y(point.y) {}

Point & Point::operator=( Point const & point)
{
	if (this != &point)
	{
		this->~Point();
		new (this) Point(point);
	}

	return *this;
}

Point Point::operator-( Point const & point ) const
{
	Fixed tmp1 = x - point.x;
	Fixed tmp2 = y - point.y;

	Point p = Point(tmp1.toFloat(), tmp2.toFloat());

	return p;
}

bool Point::operator==( Point const & point ) const
{
	return x == point.x && y == point.y;
}

Fixed const & Point::getX( void ) const
{
	return x;
}

Fixed const & Point::getY( void ) const 
{
	return y;
}

Point::~Point( void ) {}
