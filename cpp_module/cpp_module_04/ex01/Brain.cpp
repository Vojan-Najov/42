#include <iostream>
#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain default constructor called." << std::endl;
}

Brain::Brain(const Brain &other)
{
	std::cout << "Brain copy constructor called." << std::endl;
	for (unsigned int i = 0; i < ideasAmount; ++i)
	{
		ideas[i] = other.ideas[i];
	}
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor called." << std::endl;
}

Brain &Brain::operator=(const Brain &other)
{
	std::cout << "Brain copy assignment operator called." << std::endl;
	for (unsigned int i = 0; i < ideasAmount; ++i)
	{
		ideas[i] = other.ideas[i];
	}
	
	return *this;
}
