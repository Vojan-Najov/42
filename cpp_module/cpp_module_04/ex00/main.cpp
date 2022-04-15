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
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "WrongDog.hpp"

int main()
{
	{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();
		std::cout << "_____________DESTRUCTORS______________" << std::endl;
		delete meta;
		delete j;
		delete i;
	}

	std::cout << "_____________WRONG ANIMAL, CAT & DOG___________" << std::endl;
	{
		const WrongAnimal* meta = new WrongAnimal();
		const WrongAnimal* j = new WrongDog();
		const WrongAnimal* i = new WrongCat();
		const WrongCat* t = new WrongCat();

		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		std::cout << t->getType() << " " << std::endl;
		i->makeSound();
		j->makeSound();
		t->makeSound();
		meta->makeSound();
		std::cout << "_____________DESTRUCTORS______________" << std::endl;
		delete meta;
		delete j;
		delete i;
		delete t;
	}
	return 0;
}
