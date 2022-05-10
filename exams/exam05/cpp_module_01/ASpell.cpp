#include "ASpell.hpp"

ASpell::ASpell(void) : _name("No spell"), _effects("No effects") {};

ASpell::ASpell(const std::string & name, const std::string & effects)
	: _name(name), _effects(effects) {}

ASpell::ASpell(const ASpell & copy)
	: _name(copy._name), _effects(copy._effects) {}

ASpell::~ASpell(void) {}

ASpell & ASpell::operator=(const ASpell & other)
{
	if (this != &other)
	{
		_name = other._name;
		_effects = other._effects;
	}
	
	return *this;
}

const std::string & ASpell::getName(void) const
{
	return _name;
}

const std::string & ASpell::getEffects(void) const
{
	return _effects;
}

void ASpell::launch(const ATarget & target) const
{
	target.getHitBySpell(*this);
}
