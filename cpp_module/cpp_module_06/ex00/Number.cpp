/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Number.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 23:14:19 by ccartman          #+#    #+#             */
/*   Updated: 2022/04/23 23:26:04 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Number.hpp"

Number::Number(void) :
		type(type_unknown)
{
	
}

Number::Number(const Number &other) :
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

Number::e_type Number::getType(const char *str)
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
		case ''':
		{
			if (sign_flag || !*++str)
				break;
			if (*++str == ''' && !*++str)
				return type_char;
			break;
		}
		case 'n':
		{
			if (sign_flag || strncmp(++str, "an", 2)
				break;
			str += 2;
			if (!*str)
				return type_double;
			if (*str == 'f' && !*++str)
				return type_float;
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
		}
		default:
		{
			while ('0' <= *str && *str <= '9')
				++str;
			if (!*str)
				return type_int;
			if (*str++ != '.' || !*str)
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

Number	&Number::parse(const char *str)
{
	type = getType(str);
	switch (type)
	{
		case type_char:
		{
			int	tmp = *++str;
			if (
			char_value = *++str;
			
		}
		case type_int:
		{
			long tmp = strtol(str);
		}
		case type_float:
		{

		}
		case type_double:
		{

		}
	}
	return 0;
}
