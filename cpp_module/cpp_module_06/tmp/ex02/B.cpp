
#include "B.hpp"

std::ostream	&operator<<(std::ostream &out, const B &b)
{
	out << "Class<B>(" << &b << ")";
	return out;
}
