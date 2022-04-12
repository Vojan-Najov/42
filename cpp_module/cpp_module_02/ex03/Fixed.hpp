/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:24:44 by ccartman          #+#    #+#             */
/*   Updated: 2022/04/12 15:54:07 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
public:
	Fixed( void );
	Fixed( int const value_ );
	Fixed( float const value_ ); 
	Fixed( Fixed const & fixedPoint);

	Fixed & operator=( Fixed const & fixedPoint );
	bool operator>( Fixed const & fixedPoint ) const;
	bool operator<( Fixed const & fixedPoint ) const;
	bool operator>=( Fixed const & fixedPoint ) const;
	bool operator<=( Fixed const & fixedPoint ) const;
	bool operator==( Fixed const & fixedPoint ) const;
	bool operator!=( Fixed const & fixedPoint ) const;
	Fixed operator+( Fixed const & fixedPoint ) const;
	Fixed operator-( Fixed const & fixedPoint ) const;
	Fixed operator*( Fixed const & fixedPoint ) const;
	Fixed operator/( Fixed const & fixedPoint ) const;
	Fixed operator++( void );
	Fixed operator++( int );
	Fixed operator--( void );
	Fixed operator--( int );

	int getRawBits( void ) const;
	void setRawBits(int const raw);
	float toFloat( void ) const;
	int toInt( void ) const;
	static Fixed & min( Fixed & fp1, Fixed & fp2);
	static Fixed const & min( Fixed const & fp1, Fixed const & fp2);
	static Fixed & max( Fixed & fp1, Fixed & fp2);
	static Fixed const & max( Fixed const & fp1, Fixed const & fp2);

	~Fixed( void );
		
private:
	int	value;
	static const int fractBits;
};

std::ostream & operator<<( std::ostream & o, Fixed const & fixedPoint );

#endif
