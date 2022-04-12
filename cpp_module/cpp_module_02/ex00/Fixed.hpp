/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:55:48 by ccartman          #+#    #+#             */
/*   Updated: 2022/04/12 16:00:51 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
public:
	Fixed( void );
	Fixed( Fixed const & f);

	Fixed & operator=(Fixed const & f);

	int getRawBits( void ) const;
	void setRawBits(int const raw);

	~Fixed( void );
		
private:
	int	value;
	static const int fraction = 8;		
};

#endif
