#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <string>
#include <iostream>
#include "ASpell.hpp"
#include <map>

class Warlock
{
public:
	Warlock(const std::string & name, const std::string & title);
	~Warlock(void);


	const std::string & getName(void) const;
	const std::string & getTitle(void) const;
	void setTitle(const std::string & title);
	void introduce(void) const;
	void learnSpell(ASpell * spell_ptr);
	void forgetSpell(const std::string & spell_str);
	void launchSpell(const std::string & spell_name, ATarget & target);

private:
	std::string _name;
	std::string _title;
	std::map<std::string, ASpell *> _book;

	Warlock(void);
	Warlock(const Warlock &copy);
	Warlock & operator=(const Warlock & copy);
};

#endif
