
#include "C.hpp"

std::ostream	&operator<<(std::ostream &out, const C &c)
{
	out << "Class<C>(" << &c << ")";
	return out;
}
