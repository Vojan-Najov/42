/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 15:00:25 by ccartman          #+#    #+#             */
/*   Updated: 2022/04/17 15:03:12 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice") {}

Ice::Ice(const Ice &other) : AMateria("ice") {(void) other;}

Ice::~Ice(void) {}

Ice &Ice::operator=(const Ice &other)
{
	(void) other;

	return *this;
}

Ice *Ice::clone(void) const
{
	Ice *ptr = new Ice();

	return ptr;
}

void Ice::use(ICharacter &target) 
{
	std::cout << "* shoots an ice bolt at " << target.getName();
	std::cout << " *" << std::endl;
}
