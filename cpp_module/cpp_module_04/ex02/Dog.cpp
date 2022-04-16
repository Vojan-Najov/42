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

Dog::Dog(void) : AAnimal("Dog")
{
	std::cout << "Dog default constructor called." << std::endl;
	brain = new Brain();
}

Dog::Dog(const Dog &other) : AAnimal(other)
{
	std::cout << "Dog copy constructor called." << std::endl;
	brain = new Brain(*other.brain);
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called." << std::endl;
	delete brain;
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << "Dog copy assignment constructor called." << std::endl;
	AAnimal::operator=(other);
	*brain = *other.brain;

	return *this;
}

void Dog::makeSound(void) const
{
	std::cout << "Woof\a" << std::endl;
}
