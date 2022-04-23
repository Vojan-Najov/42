
#include <cstdlib>
#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base()
{

}

Base	*generate(void)
{
	int n = rand() % 3;
	if (n == 0)
	{
		A *obj = new A();
		std::cout << "Generated: " << *obj << "\n";
		return obj;
	}
	if (n == 1)
	{
		B *obj = new B();
		std::cout << "Generated: " << *obj << "\n";
		return obj;
	}
	C *obj = new C();
	std::cout << "Generated: " << *obj << "\n";
	return obj;
}

void	identify(Base *p)
{
	{
		A *obj = dynamic_cast<A*>(p);
		if (obj)
		{
			std::cout << "Identified: " << *obj << "\n";
			return;
		}
	}
	{
		B *obj = dynamic_cast<B*>(p);
		if (obj)
		{
			std::cout << "Identified: " << *obj << "\n";
			return;
		}
	}
	{
		C *obj = dynamic_cast<C*>(p);
		if (obj)
		{
			std::cout << "Identified: " << *obj << "\n";
			return;
		}
	}
	std::cout << "Identification has failed\n";
}

void	identify(Base &p)
{
	try
	{
		A &obj = dynamic_cast<A&>(p);
		std::cout << "Identified: " << obj << "\n";
		return;
	}
	catch (std::exception &e)
	{

	}
	try
	{
		A &obj = dynamic_cast<A&>(p);
		std::cout << "Identified: " << obj << "\n";
		return;
	}
	catch (std::exception &e)
	{

	}
	try
	{
		B &obj = dynamic_cast<B&>(p);
		std::cout << "Identified: " << obj << "\n";
		return;
	}
	catch (std::exception &e)
	{

	}
	try
	{
		C &obj = dynamic_cast<C&>(p);
		std::cout << "Identified: " << obj << "\n";
		return;
	}
	catch (std::exception &e)
	{

	}
	std::cout << "Identification has failed\n";
}
