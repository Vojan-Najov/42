/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 17:45:45 by ccartman          #+#    #+#             */
/*   Updated: 2022/04/14 19:59:48 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap( void ) : name("Noname")
{
	std::cout << "DiamondTrap default constructor called." << std::endl;
	ClapTrap::name = "Noname_clap_name";
	hitPoints = 100;
	attackDamage = 30;
}

DiamondTrap::DiamondTrap( std::string const & name_)
	: ClapTrap(name_ + "_clap_name"), name(name_)
{
	std::cout << "DiamondTrap string constructor called." << std::endl;
	hitPoints = 100;
	attackDamage = 30;
}

DiamondTrap::DiamondTrap( DiamondTrap const & other )
	: ClapTrap(other)
{
	std::cout << "DiamondTrap copy constructor called." << std::endl;
	name = other.name;
}

DiamondTrap::~DiamondTrap( void )
{
	std::cout << "DiamondTrap destructor called." << std::endl;
}

DiamondTrap & DiamondTrap::operator=( DiamondTrap const & other )
{
	std::cout << "DiamondTrap copy assignment operator  called." << std::endl;
	ClapTrap::operator=(other);
	name = other.name;

	return *this;
}

void DiamondTrap::whoAmI( void )
{
	std::cout << "My name is " << name << " (" << ClapTrap::name << ')';
	std::cout << std::endl;
}
