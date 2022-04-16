/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 17:19:27 by ccartman          #+#    #+#             */
/*   Updated: 2022/04/15 19:21:00 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AAnimal.hpp"

AAnimal::AAnimal(void) : type()
{
	std::cout << "AAnimal constructor called." << std::endl;
}

AAnimal::AAnimal(const std::string &type_) : type(type_)
{
	std::cout << "AAnimal string constructor called." << std::endl;
}

AAnimal::AAnimal(const AAnimal &other) : type(other.type)
{
	std::cout << "AAnimal copy constructor called." << std::endl;
}

AAnimal::~AAnimal(void)
{
	std::cout << "AAnimal destructor called." << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &other)
{
	std::cout << "AAnimal copy assignment constructor called." << std::endl;
	type = other.type;

	return *this;
}

const std::string &AAnimal::getType(void) const
{
	return type;
}
