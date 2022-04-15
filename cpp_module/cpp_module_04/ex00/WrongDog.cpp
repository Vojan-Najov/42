/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 18:42:49 by ccartman          #+#    #+#             */
/*   Updated: 2022/04/15 19:24:45 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "WrongDog.hpp"

WrongDog::WrongDog(void) : WrongAnimal("Dog")
{
	std::cout << "WrongDog constructor called." << std::endl;
}

WrongDog::WrongDog(const WrongDog &other) : WrongAnimal(other)
{
	std::cout << "WrongDog copy constructor called." << std::endl;
}

WrongDog::~WrongDog(void)
{
	std::cout << "WrongDog destructor called." << std::endl;
}

WrongDog &WrongDog::operator=(const WrongDog &other)
{
	std::cout << "WrongDog copy assignment constructor called." << std::endl;
	WrongAnimal::operator=(other);

	return *this;
}

void WrongDog::makeSound(void) const
{
	std::cout << "Woof\a" << std::endl;
}
