/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 16:23:38 by ccartman          #+#    #+#             */
/*   Updated: 2022/04/06 16:57:39 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main( void )
{
	Zombie* horde;

	horde = zombieHorde(42, "Billy Bob");
	for (int i = 0; i < 42; ++i)
	{
		horde[i].announce();
	}
	delete [] horde;
	
	return 0;
}
