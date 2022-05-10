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
	std::map<std::string, ASpell *>::iterator it = _book.begin();
	std::map<std::string, ASpell *>::iterator it_end = _book.end();
	while (it != it_end)
	{
		delete it->second;
		++it;
	}
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

void Warlock::learnSpell(ASpell * spell_ptr)
{
	if (spell_ptr)
	{
		if (_book.find(spell_ptr->getName()) == _book.end())
			_book.insert(std::pair<std::string, ASpell *>(spell_ptr->getName(), spell_ptr->clone()));
	}
}

void Warlock::forgetSpell(const std::string & spell_str)
{
	std::map<std::string, ASpell *>::iterator it = _book.find(spell_str);
	if (it != _book.end())
	{
		delete it->second;
		_book.erase(spell_str);
	}
}

void Warlock::launchSpell(const std::string & spell_name, ATarget & target)
{
	std::map<std::string, ASpell *>::iterator it = _book.find(spell_name);
	if (it == _book.end())
		return ;
	it->second->launch(target);
}
