/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 19:42:52 by ccartman          #+#    #+#             */
/*   Updated: 2022/04/06 21:15:23 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanA.hpp"

HumanA::HumanA( std::string const & name_, Weapon & weapon_ ) \
		: weapon(weapon_)
{
	name = name_;
}

void HumanA::attack( void ) const
{
	std::cout << name << " attacks with their " << weapon.getType();
	std::cout << std::endl;
}
