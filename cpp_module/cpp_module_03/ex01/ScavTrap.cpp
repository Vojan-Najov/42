/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 20:52:41 by ccartman          #+#    #+#             */
/*   Updated: 2022/04/14 00:02:56 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScavTrap.hpp"

const unsigned int ScavTrap::hitPoints = 100; 

ScavTrap::ScavTrap( void )
{
	std::cout << "ClavTrap default constructor called." << std::endl;
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
}

ScavTrap::ScavTrap( std::string name_ ) : ClapTrap(name_)
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

ScavTrap & ScavTrap::operator=(ScavTrap const & other )
{
	std::cout << "ScavTrap copy assignment operator called." << std::endl;
	this->operator=(other);
	
	return *this;
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

void ScavTrap::guardGate( void )
{

}
