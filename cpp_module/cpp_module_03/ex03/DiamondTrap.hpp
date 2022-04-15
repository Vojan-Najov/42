/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 17:39:24 by ccartman          #+#    #+#             */
/*   Updated: 2022/04/14 19:59:50 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include <string>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
public:
	DiamondTrap( void );
	DiamondTrap( std::string const & name_ );
	DiamondTrap( DiamondTrap const & other );
	~DiamondTrap( void );

	DiamondTrap & operator=( DiamondTrap const & other );

	void whoAmI( void );
	
private:
	std::string name;
};

#endif
