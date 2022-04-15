/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 18:30:57 by ccartman          #+#    #+#             */
/*   Updated: 2022/04/15 19:24:05 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : type("Animal")
{
	std::cout << "WrongAnimal constructor called." << std::endl;
}

WrongAnimal::WrongAnimal(const std::string &type_) : type(type_)
{
	std::cout << "WrongAnimal string constructor called." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : type(other.type)
{
	std::cout << "WrongAnimal copy constructor called." << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal destructor called." << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	std::cout << "WrongAnimal copy assignment constructor called." << std::endl;
	type = other.type;

	return *this;
}

const std::string &WrongAnimal::getType(void) const
{
	return type;
}

void WrongAnimal::makeSound(void) const
{
	std::cout << "AAAAAAAAAAA\a" << std::endl;
}
