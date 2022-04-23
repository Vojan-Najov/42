
#include <iomanip>
#include "Number.hpp"
#include "utils.h"

Number::Number() :
		type(type_unknown),
		has_char(),
		value_char(),
		has_int(),
		value_int(),
		has_float(),
		value_float(),
		has_double(),
		value_double()
{

}

Number::Number(char value) :
		type(type_char),
		has_char(true),
		value_char(value),
		has_int(true),
		value_int(value),
		has_float(),
		value_float(),
		has_double(),
		value_double()
{
	has_float = tryToFloat(value_int, &value_float);
	has_double = true;
	value_double = value_int;
}

Number::Number(int value) :
		type(type_int),
		has_char(),
		value_char(),
		has_int(true),
		value_int(value),
		has_float(),
		value_float(),
		has_double(true),
		value_double(value)
{
	has_char = tryToChar(value_int, &value_char);
	has_float = tryToFloat(value_int, &value_float);
}

Number::Number(float value) :
		type(type_float),
		has_char(),
		value_char(),
		has_int(),
		value_int(),
		has_float(true),
		value_float(value),
		has_double(true),
		value_double(value)
{
	has_int = tryToInt(value_double, &value_int);
	if (has_int)
		has_char = tryToChar(value_int, &value_char);
}

Number::Number(double value) :
		type(type_double),
		has_char(),
		value_char(),
		has_int(),
		value_int(),
		has_float(),
		value_float(),
		has_double(true),
		value_double(value)
{
	has_float = true;
	value_float = static_cast<float>(value_double);
	has_int = tryToInt(value_double, &value_int);
	if (has_int)
		has_char = tryToChar(value_int, &value_char);
}

Number::Number(const Number &copy) :
		type(copy.type),
		has_char(copy.has_char),
		value_char(copy.value_char),
		has_int(copy.has_int),
		value_int(copy.value_int),
		has_float(copy.has_float),
		value_float(copy.value_float),
		has_double(copy.has_double),
		value_double(copy.value_double)
{

}

Number::~Number()
{

}

Number &Number::operator=(const Number &assign)
{
	type = assign.type;
	has_char = assign.has_char;
	value_char = assign.value_char;
	has_int = assign.has_int;
	value_int = assign.value_int;
	has_float = assign.has_float;
	value_float = assign.value_float;
	has_double = assign.has_double;
	value_double = assign.value_double;
	return *this;
}

void Number::print() const
{
	bool is_fixed = true;

	if (type == type_char || type == type_int)
		is_fixed = false;
	if (!is_fixed)
		std::cout << std::setprecision(100);
	if (has_char)
	{
		if (std::isprint(value_char))
			std::cout << "char: '" << value_char << "'\n";
		else
			std::cout << "char: Non displayable\n";
	}
	else
	{
		std::cout << "char: impossible\n";
	}
	if (has_int)
	{
		std::cout << "int: " << value_int << "\n";
	}
	else
	{
		std::cout << "int: impossible\n";
	}
	if (has_float)
	{
		std::cout << "float: " << value_float;
		if (!is_fixed)
			std::cout << ".0";
		std::cout << "f\n";
	}
	else
	{
		std::cout << "float: impossible\n";
	}
	if (has_double)
	{
		std::cout << "double: " << value_double;
		if (!is_fixed)
			std::cout << ".0";
		std::cout << "\n";
	}
	else
	{
		std::cout << "double: impossible\n";
	}
}

Number::e_type	Number::guessType(const std::string &str)
{
	if (str.length() == 0)
		return (type_unknown);

	const char	*s = str.c_str();

	if (str.length() == 3)
	{
		if (s[0] == '\'' && s[2] == '\'')
			return (type_char);
		if (str == "nan" || str == "inf")
			return (type_double);
	}
	else if (str.length() == 4)
	{
		if (str == "nanf" || str == "inff")
			return (type_float);
		if (str == "-inf" || str == "+inf")
			return (type_double);
	}
	else if (str.length() == 5)
	{
		if (str == "-inff" || str == "+inff")
			return (type_float);
	}

	if (*s == '-')
		s++;
	while (*s >= '0' && *s <= '9')
		s++;
	if (*s == 0)
		return (type_int);
	if (s[0] == 'f' && s[1] == 0)
		return (type_float);
	if (*s == '.')
	{
		s++;
		if (!(*s >= '0' && *s <= '9'))
			return (type_unknown);
		s++;
		while (*s >= '0' && *s <= '9')
			s++;
		if (s[0] == 0)
			return (type_double);
		if (s[0] == 'f' && s[1] == 0)
			return (type_float);
	}
	return (type_unknown);
}

Number &Number::parse(const std::string &str)
{
	const e_type	type = guessType(str);

	Number	*number;
	char	value_char;
	int		value_int;
	float	value_float;
	double	value_double;

	if (type == type_char && tryToChar(str, &value_char))
		number = new Number(value_char);
	else if (type == type_int && tryToInt(str, &value_int))
		number = new Number(value_int);
	else if (type == type_float && tryToFloat(str, &value_float))
		number = new Number(value_float);
	else if (type == type_double && tryToDouble(str, &value_double))
		number = new Number(value_double);
	else
		number = new Number();

	return (*number);
}
