/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 19:43:17 by ccartman          #+#    #+#             */
/*   Updated: 2022/04/23 23:05:57 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

enum type
{ 
	type_char,
	type_int,
	type_float,
	type_double,
	type_unknow
};
	

int	print_error(char *err_mes);

int main(int atgc, char **argv)
{
	type	t;

	if (argc != 2)
		return print_error("One argument is expected");
	t = istype(argv[1]);
	print_types(t, argv[1]);
}

void print_types(type t, const char *str)
{
	switch (t)
	{
		case type_char:
		{
			 
			break;
		}
}

int	print_error(const char *err_mes)
{
	std::cerr << err_mess << std::endl;
	
	return 1;
}

type istype(const char *str)
{
	if (!*str)
		return type_unknow;
	if (!*(str + 1))
	{
		if (isdigit(*str))
			return type_int;
		return type_char;
	}
	else if (!strncmp(str, "nan", 3))
	{
		str += 3;
		if (!*str)
			return type_double;
		if (*str == 'f' && !*(str + 1))
			return type_float;
	}
	else if (*str == '-' || *str == '+')
	{
		if (!strncmp(++str, "inf", 3))
		{
			str += 3;
			if (!*str)
				return type_double;
			if (*str == 'f' && !*(str + 1))
				return type_float;
		}
		else
		{
			while (isdigit(*++str)) 
				;
			if (!*str)
				return type_int;
			if (*str == '.')
			{
				while (isdigit(*++str))
					;
				if (!*str)
					return type_double;
				if (*str == 'f' && !(*str))
					return type_float;
			}
		}
	}
	else
	{
		while (isdigit(*str))
			++str;
		if (!*str)
			return type_int;
		if (*str == '.')
		{
			while (isdigit(*++str))
				;
			if (!*str)
				return type_double;
			if (*str == 'f' && !(*str + 1))
				return type_float;
		}
	}
	return type_unknow;
}
