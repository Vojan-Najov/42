#include "Warlock.hpp"

Warlock::Warlock(void) {}

Warlock::Warlock(const std::string & name, const std::string & title)
	: _name(name), _title(title)
{
	std::cout << _name;
	std::cout << ": This looks like another boring day.\n";
}

Warlock::Warlock(const Warlock & copy)
	: _name(copy._name), _title(copy._title) {}

Warlock & Warlock::operator=(const Warlock & other)
{
	if (this != &other)
	{
		_name = other._name;
		_title = other._title;
	}

	return *this;
}

Warlock::~Warlock(void)
{
	std::cout << _name;
	std::cout << ": My job here is done!\n";
}

const std::string & Warlock::getName(void) const
{
	return _name;
}

const std::string & Warlock::getTitle(void) const
{
	return _title;
}

void Warlock::setTitle(const std::string & title)
{
	_title = title;
}

void Warlock::introduce(void) const
{
	std::cout << _name;
	std::cout << ": I am " << _name << ", " << _title << "!\n";
}
