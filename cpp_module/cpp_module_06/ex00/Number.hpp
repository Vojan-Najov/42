/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Number.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 23:14:23 by ccartman          #+#    #+#             */
/*   Updated: 2022/04/23 23:26:03 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NUMBER_HPP
#define NUMBER_HPP

class Number
{
public:
	enum e_type
	{
		type_unknown
		type_char,
		type_int,
		type_float,
		type_double
	};

	Number(void);
	Number(const char value);
	Number(const int value);
	Number(const float value);
	Number(const double value);
	Number(const Number &other);

	Number &operator=(const Number &other);

	static e_type getType(const char *str);
	static Number *parse(const char *str);

private:
	e_type	type;
	bool char_ok;
	char char_value;
	bool int_ok;
	int int_value;
	bool float_ok;
	float float_value;
	bool double_ok;
	double double_value;
};

std::ostream &operator<<(std::ostream &out, const Number &other);

#endif
