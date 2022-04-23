#include <iostream>
#include "utils.h"
#include "Number.hpp"

void converter(const std::string &str)
{
	Number &number = Number::parse(str);
	number.print();
	delete &number;
}

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << argv[0] << " value" << std::endl;
	}
	else
	{
		converter(argv[1]);
	}
	return (0);
}
