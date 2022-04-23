#include <cstdlib>
#include <limits>
#include <cerrno>
#include <cmath>
#include "utils.h"

bool tryToChar(const std::string &str, char *value)
{
	if (str.length() == 3 && str[0] == '\'' && str[2] == '\'')
	{
		*value = str[1];
		return (true);
	}
	return (false);
}

bool tryToChar(int value_int, char *value)
{
	char	value_char;

	value_char = static_cast<char>(value_int);
	if (value_char < 0 || value_int != value_char)
		return (false);
	*value = value_char;
	return (true);
}

bool tryToInt(const std::string &str, int *value)
{
	char	*end;
	long	value_long;

	errno = 0;
	value_long = strtol(str.c_str(), &end, 10);
	if (*end != 0)
		return (false);
	if (errno == ERANGE)
		return (false);
	if (value_long > std::numeric_limits<int>::max())
		return (false);
	if (value_long < std::numeric_limits<int>::min())
		return (false);
	*value = (int)value_long;
	return (true);
}

bool tryToInt(double value_double, int *value)
{
	int	value_int;

	if (value_double != value_double || isinf(value_double))
		return (false);
	if (value_double > std::numeric_limits<int>::max())
		return (false);
	if (value_double < std::numeric_limits<int>::min())
		return (false);
	value_int = static_cast<int>(value_double);
	*value = value_int;
	return (true);
}

bool tryToFloat(const std::string &str, float *value)
{
	char	*end;
	float	value_float;

	errno = 0;
	value_float = strtof(str.c_str(), &end);
	if (*end != 'f')
		return (false);
	if (errno == ERANGE)
		return (false);
	*value = value_float;
	return (true);
}

bool tryToFloat(int value_int, float *value)
{
	float	value_float;

	if (value_int == std::numeric_limits<int>::min())
		return (false);
	value_float = static_cast<int>(value_int);
	if (static_cast<int>(value_float) != value_int)
		return (false);
	*value = value_float;
	return (true);
}

bool tryToDouble(const std::string &str, double *value)
{
	char	*end;
	double	value_double;

	errno = 0;
	value_double = strtod(str.c_str(), &end);
	if (*end != 0)
		return (false);
	if (errno == ERANGE)
		return (false);
	*value = value_double;
	return (true);
}
