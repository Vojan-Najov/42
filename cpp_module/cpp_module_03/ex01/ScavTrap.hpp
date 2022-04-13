/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 20:46:52 by ccartman          #+#    #+#             */
/*   Updated: 2022/04/13 23:13:52 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTraap : ClapTrap
{
public:
	ScavTrap( void );
	ScavTrap( ScavTrap const & other );
	~ScavTrap( void );

	ScavTrap & operator=( ScavTrap const & );

	void guardGate( void );
};

#endif
