/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 19:58:22 by ccartman          #+#    #+#             */
/*   Updated: 2022/04/12 00:02:27 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_CPP
#define POINT_CPP

#include "Fixed.hpp"

class Point
{
public:
	Point( void );
	Point( float const f1, float const f2);
	Point( Point const & point );
	Point & operator=( Point const & point );
	Point operator-( Point const & point ) const;
	bool operator==( Point const & point ) const;
	Fixed const & getX( void ) const;
	Fixed const & getY( void ) const;
	~Point ( void );
private:
	Fixed const x;
	Fixed const y;
};

bool bsp( Point const a, Point const b, Point const c, Point const point );

#endif
