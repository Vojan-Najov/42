/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 19:54:37 by ccartman          #+#    #+#             */
/*   Updated: 2022/04/06 21:05:47 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Weapon.hpp"
#include "HumanB.hpp"

HumanB::HumanB( std::string const & name_ )
{
	name = name_;
	weapon = 0;
}

void HumanB::setWeapon( Weapon & weapon_ )
{
	weapon = &weapon_;
}

void HumanB::attack( void ) const
{
	std::cout << name << " attacks";
	if (weapon)
		std::cout << " with their " << weapon->getType(); 
	std::cout << std::endl;
}
