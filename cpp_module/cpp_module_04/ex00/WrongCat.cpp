/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 18:37:36 by ccartman          #+#    #+#             */
/*   Updated: 2022/04/15 19:24:26 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal("Cat")
{
	std::cout << "WrongCat constructor called." << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
	std::cout << "WrongCat copy constructor called." << std::endl;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destructor called." << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	std::cout << "WrongCat copy assignment constructor called." << std::endl;
	WrongAnimal::operator=(other);

	return *this;
}

void WrongCat::makeSound(void) const
{
	std::cout << "Meow\a" << std::endl;
}
