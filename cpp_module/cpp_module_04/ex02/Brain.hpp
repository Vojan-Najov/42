#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

static const unsigned int ideasAmount = 100;

class Brain
{
public:
	Brain(void);
	Brain(const Brain &other);
	~Brain(void);
	
	Brain &operator=(const Brain &other);

private:
	std::string ideas[ideasAmount];
};

#endif
