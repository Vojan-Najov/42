#include "ATarget.hpp"

ATarget::ATarget(void) : _type("No target") {};

ATarget::ATarget(const std::string & type)
	: _type(type) {}

ATarget::ATarget(const ATarget & copy)
	: _type(copy._type) {}

ATarget::~ATarget(void) {}

ATarget & ATarget::operator=(const ATarget & other)
{
	if (this != &other)
	{
		_type = other._type;
	}
	
	return *this;
}

const std::string & ATarget::getType(void) const
{
	return _type;
}

void ATarget::getHitBySpell(const ASpell & spell) const
{
	std::cout << _type << " has been ";
	std::cout << spell.getEffects() << "!\n";
}
