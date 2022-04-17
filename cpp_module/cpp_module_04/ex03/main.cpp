/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 15:23:33 by ccartman          #+#    #+#             */
/*   Updated: 2022/04/17 15:51:29 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

int main()
{
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);

		ICharacter* bob = new Character("bob");

		me->use(0, *bob);
		me->use(1, *bob);

		delete bob;
		delete me;
		delete src;
	}
	{
		std::cout << "_____________MY_TESTS______________" << std::endl;
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter* me = new Character("me");
		me->unequip(0);
		AMateria *tmp, *tmp1, *tmp2, *tmp3, *tmp4;
		tmp = src->createMateria("dsadsaas");
		if (tmp)
			std::cerr << "ERROR\n";
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp1 = src->createMateria("cure");
		me->equip(tmp1);
		me->equip(tmp1);
		tmp2 = src->createMateria("cure");
		me->equip(tmp2);
		tmp3 = src->createMateria("cure");
		me->equip(tmp3);
		tmp4 = src->createMateria("ice");
		me->equip(tmp4);
		me->unequip(3);
		me->equip(tmp4);
		

		ICharacter* bob = new Character("bob");

		me->use(0, *bob);
		me->use(1, *bob);

		Character joe = *(Character *) me;
		delete me;
		joe.use(0, *bob);
		joe.use(1, *bob);
		delete tmp3;
		delete bob;
		delete src;
	}


	return 0;
}
