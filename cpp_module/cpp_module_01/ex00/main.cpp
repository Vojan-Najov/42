/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 16:23:38 by ccartman          #+#    #+#             */
/*   Updated: 2022/04/06 16:59:53 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main( void )
{
	Zombie	bob = Zombie("Bob");
	Zombie* billy;

	billy = newZombie("Billy");
	randomChump("Joe");
	bob.announce();
	billy->announce();
	delete billy;	

	return 0;
}
