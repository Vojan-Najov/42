/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 19:38:43 by ccartman          #+#    #+#             */
/*   Updated: 2022/04/06 20:59:40 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <string>
#include "Weapon.hpp"

class HumanA
{
public:
	HumanA( std::string const & name_, Weapon & weapon_ );
	void attack( void ) const;
private:
	std::string name;
	Weapon & weapon;
};

#endif
