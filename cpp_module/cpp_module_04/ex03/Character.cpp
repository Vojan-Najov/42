#include "Character.hpp"

Character::Character(void) : name(), slotCount(0) {}

Character::Character(const std::string &name_) : name(name_), slotCount(0) {}

Character::Character(const Character &other) : name(other.name), slotCount(other.slotCount)
{
	for (int i = 0; i < slotCount; ++i)
	{
		slot[i] = other.slot[i].clone();
	}
}

Character::~Character(void)
{
	for (int i = 0; i < slotCount; ++i)
		delete slot[i];
}

Character &Character::operator=(const Character &other)
{
	name = other.name;
	while (slotCount--)
		delete slot[slotCount];
	slotCount = other.slotCount;
	for (int i = 0; i < slotCount; ++i)
		slot[i] = other.slot[i].clone();

	return *this;
}

std::string const &Character::getName(void) const
{
	return name;
}

void Character::equip(AMateria *m)
{
	if (slotCount < 4)
	{
		slot[slotCount] = m;
		++slotCount;
	}
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < slotCount)
	{
		for (int i = idx + 1; i < slotCount; ++i)
		{
			slot[i - 1] = slot[i];
		}
		slotCount--;
	}
}

void Character::use(int idx, ICharacter &target)
{
	if (0 <= idx && idx < slotCount)
	{
		slot[i].use(target);
	}
}
