#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>

class AMateria
{
	public:
		AMateria(void);
		AMateria(const std::string &type_);
		AMateria(const AMateria &other);
		virtual ~AMateria(void);

		AMateria &operator=(const AMateria &other);

		const std::string &getType(void) const;

		virtual AMateria *clone(void) const = 0;
		virtual void use(ICharacter &target);	
	protected:
		std::string type;
};

#endif
