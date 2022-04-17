/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 15:03:30 by ccartman          #+#    #+#             */
/*   Updated: 2022/04/17 15:09:24 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure") {}

Cure::Cure(const Cure &other) : AMateria("cure") {(void) other;}

Cure::~Cure(void) {}

Cure &Cure::operator=(const Cure &other)
{
	(void) other;

	return *this;
}

Cure *Cure::clone(void) const
{
	Cure *ptr = new Cure();

	return ptr;
}

void Cure::use(ICharacter &target)
{
	std::cout << "* helth " << target.getName();
	std::cout << "'s wouds *" << std::endl;
}
