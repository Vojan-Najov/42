#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <string>

class MateriaSource : public IMateriaSource
{
	public:
		MateriaSource(void);
		MateriaSource(const MateriaSource &other);
		virtual ~IMateriaSource(void) {}

		MateriaSource &operator=(const MateriaSource &other);

		virtual void learnMateria(AMateria *m);
		virtual AMateria* createMateria(std::string const &type);
	private:
		AMateria *slot[4];
		slotCount;
};

#endif
