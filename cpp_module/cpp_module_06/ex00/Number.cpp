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


