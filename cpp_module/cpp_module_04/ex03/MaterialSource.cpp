#include "MaterialSource.hpp"

MaterialSource::MaterialSource(void) : slotCount(0) {}

MaterialSource::MaterialSource(const MaterialSource &other)
	: slotCount(other.sslotCount)
{
	for (int i = 0; i < slotCount; ++i)
		slot[i] = other.slot[i].clone();
}

MaterialSource::~MaterialSource(void)
{
	for (int i = 0; i < slotCount; ++i)
		delete slot[i];
}


MaterialSource & MaterialSource::operator=(const MaterialSource &other)
{
	while (slotCount--)
		delete slot[i];
	slotCount = other.slotCount;
	for (int i = 0; i < slotCount; ++i)
		slot[i] = other.slot[i].clone();
}

void MaterialSource::learnMateria(AMateria *m)
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
		if (slot[i].getType() == type)
			return slot[i].clone()
	}
	return 0;
}
