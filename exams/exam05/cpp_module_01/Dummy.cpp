#include "Dummy.hpp"

Dummy::Dummy(void) : ATarget("Target Practice Dummy") {};

Dummy::Dummy(const Dummy & copy)
	: ATarget(copy) {}

Dummy::~Dummy(void) {}

Dummy & Dummy::operator=(const Dummy & other)
{
	if (this != &other)
	{
		ATarget::operator=(other);
	}
	
	return *this;
}

ATarget * Dummy::clone(void) const
{
	ATarget *ptr = new Dummy();

	return ptr;
}
