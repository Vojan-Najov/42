/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 18:13:03 by ccartman          #+#    #+#             */
/*   Updated: 2022/04/15 19:33:13 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	{
		std::cout << "___________DOGS___________" << std::endl;
		Dog basic;
		Dog tmp;
		tmp = basic;
		{
			Dog tmp = basic;
			std::cout << "___________DESTRUCTORS___________" << std::endl;
		}
	}	
	{
		std::cout << "___________CATS____________" << std::endl;
		Cat basic;
		Cat tmp;
		tmp = basic;
		{
			Cat tmp = basic;
			std::cout << "___________DESTRUCTORS___________" << std::endl;
		}
	}
	{
		std::cout << "___________ANIMAL_PTR___________" << std::endl;
		AAnimal *dogPtr = new Dog();
		AAnimal *catPtr = new Cat();
		dogPtr->makeSound();
		catPtr->makeSound();
		std::cout << "___________DESTRUCTORS___________" << std::endl;
		delete dogPtr;
		delete catPtr;
	}
	return 0;
}
