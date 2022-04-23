
#include <iostream>
#include <cstdlib>
#include "Base.hpp"

void test_identify_by_ptr()
{
	std::cout << "\n<-- test_identify_by_ptr -->\n";

	for (int i = 0; i < 10; i++)
	{
		Base *obj = generate();
		identify(obj);
		delete obj;
	}
}

void test_identify_by_ptr_unknown()
{
	std::cout << "\n<-- test_identify_by_ptr_unknown -->\n";

	Base obj;
	identify(&obj);
}

void test_identify_by_ref()
{
	std::cout << "\n<-- test_identify_by_ref -->\n";

	for (int i = 0; i < 10; i++)
	{
		Base *obj = generate();
		identify(*obj);
		delete obj;
	}
}

void test_identify_by_ref_unknown()
{
	std::cout << "\n<-- test_identify_by_ref_unknown -->\n";

	Base obj;
	identify(obj);
}

int main()
{
	srand( time(0) );

	test_identify_by_ptr();
	test_identify_by_ptr_unknown();
	test_identify_by_ref();
	test_identify_by_ref_unknown();
	return 0;
}
