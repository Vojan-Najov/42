/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 20:46:52 by ccartman          #+#    #+#             */
/*   Updated: 2022/04/14 19:08:30 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap
{
public:
	ScavTrap( void );
	ScavTrap( std::string const & name_ );
	ScavTrap( ScavTrap const & other );
	~ScavTrap( void );

	ScavTrap & operator=(ScavTrap const & other );

	void attack( const std::string & target );
	void guardGate( void ) const;
};

#endif
