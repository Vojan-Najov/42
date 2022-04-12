/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:24:53 by ccartman          #+#    #+#             */
/*   Updated: 2022/04/12 16:14:46 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include <cmath>

const int Fixed::fractBits = 8;

static const int fixedUnit = 1 << 8;

Fixed::Fixed( void )
{
	value = 0;
}

Fixed::Fixed( int const value_ )
{
	value = value_ << fractBits;
}

Fixed::Fixed( float const value_ )
{
	value = (int) roundf(value_ * (float) fixedUnit);
}

Fixed::Fixed( Fixed const & fixedPoint )
{
	*this = fixedPoint;
}

int Fixed::getRawBits( void ) const
{
	return value;
}

void Fixed::setRawBits( int const raw )
{
	value = raw;
}

float Fixed::toFloat( void ) const
{
	return (float) value / (float) fixedUnit;
}

int Fixed::toInt( void ) const
{
	return value >> fractBits;
}

Fixed & Fixed::operator=( Fixed const & fixedPoint )
{
	value = fixedPoint.getRawBits();
	return *this;
}

bool Fixed::operator>( Fixed const & fixedPoint ) const
{
	return value > fixedPoint.value;
}

bool Fixed::operator<( Fixed const & fixedPoint ) const
{
	return value < fixedPoint.value;
}

bool Fixed::operator>=( Fixed const & fixedPoint ) const
{
	return value >= fixedPoint.value;
}

bool Fixed::operator<=( Fixed const & fixedPoint ) const
{
	return value <= fixedPoint.value;
}

bool Fixed::operator==( Fixed const & fixedPoint ) const
{
	return value == fixedPoint.value;
}

bool Fixed::operator!=( Fixed const & fixedPoint ) const
{
	return value != fixedPoint.value;
}

Fixed Fixed::operator+( Fixed const & fixedPoint ) const
{
	Fixed res;

	res.value = value + fixedPoint.value;
	return res;
}

Fixed Fixed::operator-( Fixed const & fixedPoint ) const
{
	Fixed res;

	res.value = value - fixedPoint.value;
	return res;
}

Fixed Fixed::operator*( Fixed const & fixedPoint ) const
{
	Fixed res;

	res.value = (value * fixedPoint.value) >> fractBits;
	return res;
}

Fixed Fixed::operator/( Fixed const & fixedPoint ) const
{
	Fixed res;

	res.value = (value << fractBits) / fixedPoint.value;
	return res;
}

Fixed Fixed::operator++( void )
{
	++value;
	return *this;
}

Fixed Fixed::operator++( int )
{
	Fixed tmp = *this;

	value++;
	return tmp;
}

Fixed Fixed::operator--( void )
{
	--value;
	return *this;
}

Fixed Fixed::operator--( int )
{
	Fixed tmp = *this;

	value--;
	return tmp;
}

Fixed & Fixed::min( Fixed & fp1, Fixed & fp2)
{
	return fp1.getRawBits() < fp2.getRawBits() ? fp1 : fp2;
}

Fixed const & Fixed::min( Fixed const & fp1, Fixed const & fp2)
{
	return fp1.getRawBits() < fp2.getRawBits() ? fp1 : fp2;
}

Fixed & Fixed::max( Fixed & fp1, Fixed & fp2)
{
	return fp1.getRawBits() > fp2.getRawBits() ? fp1 : fp2;
}

Fixed const & Fixed::max( Fixed const & fp1, Fixed const & fp2)
{
	return fp1.getRawBits() > fp2.getRawBits() ? fp1 : fp2;
}

std::ostream & operator<<(std::ostream & o, Fixed const & fixedPoint)
{
	o << fixedPoint.toFloat();
	return o;
}

Fixed::~Fixed( void ) {}
