/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 20:52:41 by ccartman          #+#    #+#             */
/*   Updated: 2022/04/14 16:17:29 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void )
{
	std::cout << "ScavTrap default constructor called." << std::endl;
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
}

ScavTrap::ScavTrap( std::string const & name_ ) : ClapTrap(name_)
{
	std::cout << "ScavTrap string constructor called." << std::endl;
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
}

ScavTrap::ScavTrap( ScavTrap const & other) : ClapTrap(other)
{
	std::cout << "ScavTrap copy constructor called." << std::endl;
}

ScavTrap::~ScavTrap( void )
{
	std::cout << "ScavTrap destructor called." << std::endl;
}

void ScavTrap::attack( const std::string & target )
{
	if (hitPoints && energyPoints)
	{
		--energyPoints;
		std::cout << "ScavTrap " << name << " attacks " << target;
		std::cout << ", causing " << attackDamage << " points of damage!";
		std::cout << std::endl;
	}
}

void ScavTrap::guardGate( void ) const
{
	std::cout << "ScavTrap " << name << " is now in Gate keeper mode";
	std::cout << std::endl;
}
