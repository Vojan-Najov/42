
#include "A.hpp"

std::ostream	&operator<<(std::ostream &out, const A &a)
{
	out << "Class<A>(" << &a << ")";
	return out;
}
