
#include "Data.hpp"

Data::Data()
{

}

Data::Data(const std::string &secret) : secret(secret)
{

}

Data::Data(const Data &copy) : secret(copy.secret)
{

}

Data::~Data()
{

}

Data &Data::operator=(const Data &assign)
{
	if (this != &assign)
	{
		secret = assign.secret;
	}
	return *this;
}

const std::string &Data::getSecret() const
{
	return secret;
}

uintptr_t serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}
