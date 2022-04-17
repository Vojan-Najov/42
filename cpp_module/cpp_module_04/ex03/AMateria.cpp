/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 14:51:59 by ccartman          #+#    #+#             */
/*   Updated: 2022/04/17 15:00:07 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AMateria.hpp"

AMateria::AMateria(void) : type("Materia") {};

AMateria::AMateria(const std::string &type_) : type(type_) {};

AMateria::AMateria(const AMateria &other) : type(other.type) {};

AMateria::~AMateria(void) {};

AMateria &AMateria::operator=(const AMateria &other)
{
	(void) other;

	return *this;
}

const std::string &AMateria::getType(void) const
{
	return type;
}

void AMateria::use(ICharacter &target)
{
	(void) target;
	std::cout << "AMateria use method called." << std::endl;
}
