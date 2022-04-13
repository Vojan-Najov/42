/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 22:01:34 by ccartman          #+#    #+#             */
/*   Updated: 2022/04/12 22:15:01 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main( void )
{
	ClapTrap a;
	ClapTrap bob = ClapTrap("Bob");
	ClapTrap c = a;
	ClapTrap joe = ClapTrap("Joe");

	a = c;

	bob.attack("Joe");
	joe.takeDamage(5);
	joe.beRepaired(7);
	joe.attack("Bob");
	bob.takeDamage(11);
	bob.beRepaired(10);

	return 0;
}
