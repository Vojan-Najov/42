#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure") {}

Cure::Cure(const Cure &other) : AMateria("cure") {}

Cure::~Cure(void) {}

Cure &Cure::operator=(const Cure &other)
{
	return *this;
}

Cure *Cure::clone(void) const
{
	Cure *ptr = new Cure();

	return ptr;
}

void Cure::use(ICharacter &target)
{
	std::cout << "* helth 's wouds *" << std::endl;
}
