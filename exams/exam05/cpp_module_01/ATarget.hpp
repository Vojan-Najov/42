#ifndef ATARGET_HPP
#define ATARGET_HPP

#include <string>
#include <iostream>

class ASpell;

class ATarget
{
public:
	ATarget(void);
	ATarget(const std::string & type);
	ATarget(const ATarget & copy);
	virtual ~ATarget(void);

	ATarget & operator=(const ATarget & other);

	const std::string & getType(void) const;
	virtual ATarget * clone(void) const = 0;
	void getHitBySpell(const ASpell & spell) const;
protected:
	std::string _type;

};

#include "ASpell.hpp"

#endif
