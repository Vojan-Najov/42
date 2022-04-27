/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 23:14:19 by ccartman          #+#    #+#             */
/*   Updated: 2022/04/27 14:41:39 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <cstring>
#include <climits>
#include <cfloat>
#include <cctype>
#include <cerrno>
#include <iostream>
#include <iomanip>
#include <cmath>
#include "Scalar.hpp"

static bool is_number(float f);

static bool is_number(double d);

Scalar::Scalar(void) :
		type(type_unknown)
{
	
}

Scalar::Scalar(const Scalar &other) :
		type(other.type),
		char_ok(other.char_ok),
		char_value(other.char_value),
		int_ok(other.int_ok),
		int_value(other.int_value),
		float_ok(other.float_ok),
		float_value(other.float_value),
		double_ok(other.double_ok),
		double_value(other.double_value)
{

}

Scalar::Scalar(const char *str)
		: char_ok(true),
		  int_ok(true),
		  float_ok(true),
		  double_ok(true)
{
	type = getType(str);

	errno = 0;
	switch (type)
	{
		case type_char:
		{
			if (*str == '\'' && *(str + 1))
				++str;
			char c = *str;
			char_value = c;
			int_value = static_cast<int>(c);
			float_value = static_cast<float>(c);
			double_value = static_cast<double>(c);
			break;
		}
		case type_int:
		{
			long int li = strtol(str, NULL, 10);
			int	i = (int) li;
			if (errno == ERANGE || li > INT_MAX || li < INT_MIN)
			{
				double_ok = float_ok = char_ok = int_ok = false;
				break;
			}
			if (li > SCHAR_MAX || li < SCHAR_MIN)
				char_ok = false;
			char_value = static_cast<char>(i);
			int_value = static_cast<int>(i);
			float_value = static_cast<float>(i);
			double_value = static_cast<double>(i);
			break;
		}
		case type_float:
		{
			float f = strtof(str, NULL);
			if (errno == ERANGE)
			{
				double_ok = float_ok = char_ok = int_ok = false;
				break;
			}
			if (!is_number(f))
				char_ok = int_ok = false;
			else if (f - (float) INT_MAX > 0.f || f - (float) INT_MIN < 0.f)
				char_ok = int_ok = false;
			else if (f - (float) CHAR_MIN < 0.f || f - (float) CHAR_MAX > 0.f)
				char_ok = false;
			char_value = static_cast<char>(f);
			int_value = static_cast<int>(f);
			float_value = f;
			double_value = static_cast<double>(f);
			break;
		}
		case type_double:
		{
			double d = strtod(str, NULL);
			if (errno == ERANGE)
			{
				double_ok = float_ok = char_ok = int_ok = false;
				break;
			}
			if (!is_number(d))
				char_ok = int_ok = false;
			else if (fabs(d) - (double) FLT_MAX > 0.0)
			{
				char_ok = int_ok = float_ok = false;
			}
			else if (d - (double) INT_MAX > 0.0 || d - (double) INT_MIN < 0.0)
				char_ok = int_ok = false;
			else if (d - (double) CHAR_MIN < 0.0 || d - (double) CHAR_MAX > 0.0)
				char_ok = false;
			char_value = static_cast<char>(d);
			int_value = static_cast<int>(d);
			float_value = static_cast<float>(d);
			double_value = d;
			break;
		}
		default:
		{
			char_ok = int_ok = float_ok = double_ok = false;
		}
	}
}

Scalar &Scalar::operator=(const Scalar &other)
{
	if (this != &other)
	{
		type = other.type;
		char_ok = other.char_ok;
		char_value = other.char_value;
		int_ok = other.int_ok;
		int_value = other.int_value;
		float_ok = other.float_ok;
		float_value = other.float_value;
		double_ok = other.double_ok;
		double_value = other.double_value;
	}

	return *this;
}

void Scalar::print(void) const
{
	double	int_part, fract_part;
	bool flag = false;

	std::cout << "char: ";
	if (char_ok)
	{
		if (isprint(char_value) && !isspace(char_value))
			std::cout << '\'' <<  char_value << '\'';
   		else
			std::cout << "Non displayed";
	}
	else
		std::cout << "imposible";
	std::cout << "\nint: ";
	if (int_ok)
		std::cout << int_value;
	else 
		std::cout << "imposible";
	std::cout << "\nfloat: ";
	fract_part = modf(double_value, &int_part);
	if (fract_part < 1e-30)
	{
		flag = true;
		std::cout << std::setprecision(1);
		std::cout << std::fixed;
	}
	else
	{
		std::cout << std::setprecision(30);
		std::cout << std::fixed;
	}
	if (float_ok)
	{
		std::cout << float_value;
		std::cout << 'f';
	}
	else
		std::cout << "imposible";
	std::cout << "\ndouble: ";
	if (double_ok)
		std::cout << double_value;
	else
		std::cout << "imposible";
	std::cout << std::endl;
}

Scalar::e_type Scalar::getType(const char *str)
{
	int	sign_flag(0);

	if (*str == '-' || *str == '+')
	{
		sign_flag = 1;
		++str;
	}
	switch (*str)
	{
		case 0:
		case '.':
			break;
		case '\'':
		{
			if (sign_flag)
				break;
			if (!*++str)
				return type_char;
			if (*++str == '\'' && !*++str)
				return type_char;
			break;
		}
		case 'n':
		{
			if (sign_flag || strncmp(++str, "an", 2))
				break;
			str += 2;
			if (!*str)
				return type_double;
			if (*str == 'f' && !*++str)
				return type_float;
			break;
		}
		case 'i':
		{
			if (strncmp(++str, "nf", 2))
				break;
			str += 2;
			if (!*str)
				return type_double;
			if (*str == 'f' && !*++str)
				return type_float;
			break;
		}
		default:
		{
			if (!isdigit(*str) && !*(str + 1))
				return type_char;
			while ('0' <= *str && *str <= '9')
				++str;
			if (!*str)
				return type_int;
			if (*str == 'f' && !*(str + 1))
				return type_float;
			if (*str++ != '.' || !*str || *str == 'f')
				break;
			while ('0' <= *str && *str <= '9')
				++str;
			if (!*str)
				return type_double;
			if (*str++ == 'f' && !*str)
				return type_float;
			break;
		}
	}
	return type_unknown;
}

static bool is_number(float f)
{
	int *i = (int *) &f;
	int	e;
	
	e = (*i >> 23) & 0xFF ;
	if (e == 0xFF)
		return false;
	return true;
}

static bool is_number(double d)
{
	int *p = (int *) &d;
	int e;

	++p;
	e = (*p >> 20) & 0x7FF;
	if (e == 0x7FF)
		return false;
	return true;
}
