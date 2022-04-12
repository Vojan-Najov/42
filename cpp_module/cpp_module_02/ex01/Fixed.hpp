/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:24:44 by ccartman          #+#    #+#             */
/*   Updated: 2022/04/11 16:59:21 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
public:
	Fixed( void );
	Fixed( int const value_ );
	Fixed( float const value_ ); 
	Fixed( Fixed const & fixedPoint);

	Fixed & operator=(Fixed const & fixedPoint);

	int getRawBits( void ) const;
	void setRawBits(int const raw);
	float toFloat( void ) const;
	int toInt( void ) const;

	~Fixed( void );
		
private:
	int	value;
	static const int fractBits;
};

std::ostream & operator<<(std::ostream & o, Fixed const & fixedPoint);

#endif
