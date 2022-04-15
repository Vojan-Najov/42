/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 18:08:20 by ccartman          #+#    #+#             */
/*   Updated: 2022/04/15 19:21:55 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
	std::cout << "Dog constructor called." << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << "Dog copy constructor called." << std::endl;
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called." << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << "Dog copy assignment constructor called." << std::endl;
	Animal::operator=(other);

	return *this;
}

void Dog::makeSound(void) const
{
	std::cout << "Woof\a" << std::endl;
}
