/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 19:47:47 by ccartman          #+#    #+#             */
/*   Updated: 2022/04/08 19:08:10 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B
#define HUMAN_B

#include <string>

class HumanB
{
public:
	HumanB( std::string const & name );
	void attack( void ) const;
	void setWeapon( Weapon const & weapon_ );
private:
	std::string const name;
	Weapon const * weapon;
};

#endif
