/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 22:01:34 by ccartman          #+#    #+#             */
/*   Updated: 2022/04/14 20:01:15 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"
#include "DiamondTrap.hpp"

int main( void )
{

	std::cout << "\n_________DiamondTrap_____________\n";
	DiamondTrap st1;
	std::cout << std::endl;
	DiamondTrap john = DiamondTrap("John");
	std::cout << std::endl;
	DiamondTrap bob("Bob");
	std::cout << std::endl;
	DiamondTrap st2 = st1;
	std::cout << std::endl;
	st2 = st1;
	std::cout << std::endl;

	john.attack("Bob");
	john.takeDamage(5);
	john.beRepaired(7);
	john.guardGate();
	john.highFiveGuys();
	john.whoAmI();


	std::cout << "\n_________Destructors_____________\n";
	return 0;
}
