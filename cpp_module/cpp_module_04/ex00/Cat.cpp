/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 18:01:02 by ccartman          #+#    #+#             */
/*   Updated: 2022/04/15 19:22:11 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat")
{
	std::cout << "Cat constructor called." << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << "Cat copy constructor called." << std::endl;
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called." << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << "Cat copy assignment constructor called." << std::endl;
	Animal::operator=(other);

	return *this;
}

void Cat::makeSound(void) const
{
	std::cout << "Meow\a" << std::endl;
}
