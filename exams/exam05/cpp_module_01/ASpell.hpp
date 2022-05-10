#ifndef ASPELL_HPP
#define ASPELL_HPP

#include <string>
#include <iostream>
class ATarget;

class ASpell
{
public:
	ASpell(void);
	ASpell(const std::string & name, const std::string & effects);
	ASpell(const ASpell & copy);
	virtual ~ASpell(void);

	ASpell & operator=(const ASpell & other);

	const std::string & getName(void) const;
	const std::string & getEffects(void) const;
	virtual ASpell * clone(void) const = 0;
	void launch(const ATarget & target) const;
protected:
	std::string _name;
	std::string _effects;

};

#include "ATarget.hpp"

#endif
