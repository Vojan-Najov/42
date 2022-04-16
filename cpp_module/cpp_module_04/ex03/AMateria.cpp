#include "AMateria.hpp"

AMateria::AMateria(void) : type() {};

AMateria::AMateria(const std::string &type_) : type(type_) {};

AMateria::AMateria(const AMateria &other) : type(other.type) {};

AMateria::~AMateria(void) {};

AMateria &AMateria::operator=(const AMateria &other)
{
	type = other.type;

	return *this;
}

const std::string &AMateria::getType(void) const
{
	return type;
}

void AMateria::use(ICharacter &target)
{
	(void) target;
	std::cout << "AMaterial use method called." << std::endl;
}
