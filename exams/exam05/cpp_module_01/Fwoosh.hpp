#ifndef FWOOSH_HPP
#define FWOOSH_HPP

#include <string>
#include <iostream>
#include "ASpell.hpp"

class Fwoosh : public ASpell
{
public:
	Fwoosh(void);
	Fwoosh(const Fwoosh & copy);
	virtual ~Fwoosh(void);

	Fwoosh & operator=(const Fwoosh & other);

	virtual ASpell * clone(void) const;
};

#endif
