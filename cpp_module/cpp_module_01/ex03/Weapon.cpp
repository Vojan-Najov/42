/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 19:13:02 by ccartman          #+#    #+#             */
/*   Updated: 2022/04/06 20:21:01 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( std::string const & type_ )
{
	type = type_;
}

std::string const & Weapon::getType( void ) const
{
	return type;
}

void Weapon::setType(std::string const & type_)
{
	type = type_;
}
