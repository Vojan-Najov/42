/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 20:06:04 by ccartman          #+#    #+#             */
/*   Updated: 2022/04/13 23:10:09 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap
{
public:
	ClapTrap( void );
	ClapTrap( std::string name_ );
	ClapTrap( ClapTrap const & other);
	~ClapTrap( void );

	ClapTrap & operator=( ClapTrap const & other );

	void attack( const std::string & target );
	void takeDamage( unsigned int ammount );
	void beRepaired( unsigned int amount );

protected:
	std::string name;
	unsigned int hitPoints;
	unsigned int energyPoints;
	unsigned int attackDamage;
};

#endif
