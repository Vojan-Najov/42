/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:55:45 by ccartman          #+#    #+#             */
/*   Updated: 2022/04/12 16:00:49 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed( void )
{
	std::cout << "Default constructor called." << std::endl;
	value = 0;
}

Fixed::Fixed( Fixed const & f) 
{
	std::cout << "Copy constructor called." << std::endl;
	*this = f;
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called." << std::endl;
	return value;
}

void Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called." << std::endl;
	value = raw;
}

Fixed & Fixed::operator=( Fixed const & f )
{
	std::cout << "Copy assignment operator called." << std::endl;
	value = f.getRawBits();
	return *this;
}

Fixed::~Fixed( void )
{
	std::cout << "Destructor called." << std::endl;
}
