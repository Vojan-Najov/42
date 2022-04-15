/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 20:08:58 by ccartman          #+#    #+#             */
/*   Updated: 2022/04/14 20:10:08 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void )
	: name("Noname"), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "Default constructor called." << std::endl;
}

ClapTrap::ClapTrap( std::string name_ )
	: name(name_), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "String constructor called." << std::endl;
}

ClapTrap::ClapTrap( ClapTrap const & other)
{
	std::cout << "Copy constructor called." << std::endl;
	name = other.name;
	hitPoints = other.hitPoints;
	energyPoints = other.energyPoints;
	attackDamage = other.attackDamage;
}

ClapTrap::~ClapTrap( void )
{
	std::cout << "Destructor called." << std::endl;
}

ClapTrap & ClapTrap::operator=(ClapTrap const & other )
{
	std::cout << "Copy assignment operator called." << std::endl;
	name = other.name;
	hitPoints = other.hitPoints;
	energyPoints = other.energyPoints;
	attackDamage = other.attackDamage;
	
	return *this;
}

void ClapTrap::attack( const std::string & target )
{
	if (hitPoints && energyPoints)
	{
		--energyPoints;
		std::cout << "ClapTrap " << name << " attacks " << target;
		std::cout << ", causing " << attackDamage << " points of damage!";
		std::cout << std::endl;
	}
}

void ClapTrap::takeDamage( unsigned int amount )
{
	if (hitPoints)
	{
		hitPoints = hitPoints < amount ? 0 : hitPoints - amount;
		std::cout << "ClapTrap " << name << " taking " << amount;
		std::cout << " points of damage. ";
		std::cout << "Hit points is " << hitPoints<< std::endl;
	}
}

void ClapTrap::beRepaired( unsigned int amount )
{
	if (hitPoints && energyPoints)
	{
		--energyPoints;
		hitPoints += amount;
		std::cout << "ClapTrap " << name << " repaire " << amount;
		std::cout << " points of hit. Hit points is ";
		std::cout << hitPoints << ", Energy points is ";
	    std::cout << energyPoints << std::endl;
	}
}
