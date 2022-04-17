/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 15:18:19 by ccartman          #+#    #+#             */
/*   Updated: 2022/04/17 15:22:21 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) : slotCount(0) {}

MateriaSource::MateriaSource(const MateriaSource &other)
	: slotCount(other.slotCount)
{
	for (int i = 0; i < slotCount; ++i)
		slot[i] = other.slot[i]->clone();
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < slotCount; ++i)
		delete slot[i];
}


MateriaSource & MateriaSource::operator=(const MateriaSource &other)
{
	while (slotCount--)
		delete slot[slotCount];
	slotCount = other.slotCount;
	for (int i = 0; i < slotCount; ++i)
		slot[i] = other.slot[i]->clone();

	return *this;
}

void MateriaSource::learnMateria(AMateria *m)
{
	if (slotCount < 4)
	{
		slot[slotCount] = m;
		++slotCount;
	}
}

AMateria *MateriaSource::createMateria(const std::string &type)
{
	for (int i = 0; i < slotCount; ++i)
	{	
		if (slot[i]->getType() == type)
			return slot[i]->clone();
	}
	return 0;
}
