#include "Fwoosh.hpp"

Fwoosh::Fwoosh(void) : ASpell("Fwoosh", "fwooshed") {}

Fwoosh::Fwoosh(const Fwoosh & copy)
	: ASpell(copy) {}

Fwoosh::~Fwoosh(void) {}

Fwoosh & Fwoosh::operator=(const Fwoosh & other)
{
	if (this != &other)
	{
		ASpell::operator=(other);
	}
	
	return *this;
}

ASpell * Fwoosh::clone(void) const
{
	Fwoosh *ptr = new Fwoosh();

	return ptr;
}
