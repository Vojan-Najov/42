#ifndef CURE_HPP
#define CURE_HPP

#include "AMaterial.hpp"

class Cure : public AMaterial
{
	Cure(void);
	Cure(const Cure &other);
	~Cure(void);

	Cure &operator=(const Cure &other);

	virtual Cure *clone(void) const;
	virtual void use(ICharacter &target);
};

#endif
