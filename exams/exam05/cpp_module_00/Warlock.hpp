#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <string>
#include <iostream>

class Warlock
{
public:
	Warlock(const std::string & name, const std::string & title);
	~Warlock(void);


	const std::string & getName(void) const;
	const std::string & getTitle(void) const;
	void setTitle(const std::string & title);
	void introduce(void) const;
private:
	std::string _name;
	std::string _title;

	Warlock(void);
	Warlock(const Warlock &copy);
	Warlock & operator=(const Warlock & copy);
};

#endif
