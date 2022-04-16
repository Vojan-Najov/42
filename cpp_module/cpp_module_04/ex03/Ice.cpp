#include <iostream>
#include "Ice.hpp"

Ice::Ice(void) : AMaterial("ice") {}

Ice::Ice(const Ice &other) : AMaterial("ice") {}

Ice::~Ice(void) {}

Ice &Ice::operator=(const Ice &other)
{
	return *this;
}

Ice *Ice::clone(void) const
{
	Ice *ptr = new Ice();

	return ptr;
}

void Ice::use(ICharacter &target) 
{
	std::cout << "* shoots an ice bolt at *" << std::endl;
}
