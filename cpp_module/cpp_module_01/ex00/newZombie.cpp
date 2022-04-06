/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 16:13:21 by ccartman          #+#    #+#             */
/*   Updated: 2022/04/06 16:30:14 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <new>
#include "Zombie.hpp"

Zombie* newZombie( std::string name )
{
	Zombie* z = new Zombie(name);

	return z;
}
