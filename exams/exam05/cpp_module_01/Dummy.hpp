#ifndef DUMMY_HPP
#define DUMMY_HPP

#include "ATarget.hpp"

class Dummy : public ATarget
{
public:
	Dummy(void);
	Dummy(const Dummy & copy);
	virtual ~Dummy(void);

	Dummy & operator=(const Dummy & other);

	virtual ATarget * clone(void) const;
};

#endif
