#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter
{
	public:
		Character(void);
		Character(const std::string name_);
		Character(const Character &other);
		virtual ~ICharacter(void);
		
		Character &operator=(const Character &other);

		virtual std::string const &getName(void) const;
		virtual void equip(AMateria *m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter &target);
	private:
		std::string name;
		AMateria *slot[4];
		slotCount;
};

#endif
