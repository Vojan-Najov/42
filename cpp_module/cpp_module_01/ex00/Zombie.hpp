/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 16:00:28 by ccartman          #+#    #+#             */
/*   Updated: 2022/04/06 17:14:32 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class	Zombie
{
public:
	Zombie(std::string name = "");
	~Zombie( void );
	void announce( void ) const;
private:
	std::string _name;
};

Zombie* newZombie( std::string name );

void randomChump( std:: string name );

#endif
