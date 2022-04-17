/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 17:19:27 by ccartman          #+#    #+#             */
/*   Updated: 2022/04/15 19:56:45 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"

Animal::Animal(void) : type("Animal")
{
	std::cout << "Animal constructor called." << std::endl;
}

Animal::Animal(const std::string &type_) : type(type_)
{
	std::cout << "Animal string constructor called." << std::endl;
}

Animal::Animal(const Animal &other) : type(other.type)
{
	std::cout << "Animal copy constructor called." << std::endl;
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor called." << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
	std::cout << "Animal copy assignment constructor called." << std::endl;
	type = other.type;

	return *this;
}

const std::string &Animal::getType(void) const
{
	return type;
}

void Animal::makeSound(void) const
{
	std::cout << "AAAAAAAAAAA\a" << std::endl;
}
