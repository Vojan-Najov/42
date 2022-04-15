/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 16:32:57 by ccartman          #+#    #+#             */
/*   Updated: 2022/04/14 17:01:15 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"

FragTrap::FragTrap( void )
{
	std::cout << "FragTrap default constructor called." << std::endl;
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
}

FragTrap::FragTrap( std::string const & name_ ) : ClapTrap(name_)
{
	std::cout << "FragTrap string constructor called." << std::endl;
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
}

FragTrap::FragTrap( FragTrap const & other) : ClapTrap(other)
{
	std::cout << "FragTrap copy constructor called." << std::endl;
}

FragTrap::~FragTrap( void )
{
	std::cout << "FragTrap destructor called." << std::endl;
}

FragTrap & FragTrap::operator=( FragTrap const & other )
{
	std::cout << "FragTrap copy assignment operator called." << std::endl;
	ClapTrap::operator=(other);

	return *this;
}

void FragTrap::highFiveGuys( void ) const
{
	std::cout << "FragTrap " << name << " send a positive high fives request";
	std::cout << std::endl;
}
