/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 22:01:34 by ccartman          #+#    #+#             */
/*   Updated: 2022/04/14 16:14:26 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main( void )
{
	std::cout << "_________ClapTrap_____________\n";
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

	std::cout << "\n_________ScavTrap_____________\n";
	ScavTrap st1;
	ScavTrap john = ScavTrap("John");
	ScavTrap st2 = st1;
	st2 = st1;

	john.attack("Joe");
	john.takeDamage(5);
	john.beRepaired(7);
	john.guardGate();

	std::cout << "\n_________Destructors_____________\n";

	return 0;
}
