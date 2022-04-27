/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 23:14:23 by ccartman          #+#    #+#             */
/*   Updated: 2022/04/27 14:40:21 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_HPP
#define SCALAR_HPP

class Scalar
{
public:
	enum e_type
	{
		type_unknown,
		type_char,
		type_int,
		type_float,
		type_double
	};

	Scalar(void);
	Scalar(const char *str);
	Scalar(const Scalar &other);

	Scalar &operator=(const Scalar &other);

	void print(void) const;

	static e_type getType(const char *str);

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

#endif
