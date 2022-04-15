/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 22:01:34 by ccartman          #+#    #+#             */
/*   Updated: 2022/04/14 17:06:30 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

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

	std::cout << "\n_________FragTrap_____________\n";
	FragTrap st1;
	FragTrap john = FragTrap("John");
	FragTrap st2 = st1;
	st2 = st1;

	john.attack("Joe");
	john.takeDamage(5);
	john.beRepaired(7);
	john.highFiveGuys();

	std::cout << "\n_________Destructors_____________\n";

	return 0;
}
