/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:24:53 by ccartman          #+#    #+#             */
/*   Updated: 2022/04/11 17:28:41 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include <cmath>

const int Fixed::fractBits = 8;

static const int fixedUnit = 1 << 8;

Fixed::Fixed( void )
{
	std::cout << "Default constructor called." << std::endl;
	value = 0;
}

Fixed::Fixed( int const value_ )
{
	std::cout << "Int constructor called." << std::endl;
	value = value_ << fractBits;
}

Fixed::Fixed( float const value_ )
{
	std::cout << "Float constructor called." << std::endl;
	value = (int) roundf(value_ * (float) fixedUnit);
}

Fixed::Fixed( Fixed const & fixedPoint )
{
	std::cout << "Copy constructor called." << std::endl;
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
	std::cout << "Copy assignment operator called." << std::endl;
	value = fixedPoint.getRawBits();
	return *this;
}

Fixed::~Fixed( void )
{
	std::cout << "Destructor called." << std::endl;
}

std::ostream & operator<<(std::ostream & o, Fixed const & fixedPoint)
{
	o << fixedPoint.toFloat();
	return o;
}
