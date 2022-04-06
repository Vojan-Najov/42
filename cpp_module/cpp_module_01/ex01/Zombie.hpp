/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 16:00:28 by ccartman          #+#    #+#             */
/*   Updated: 2022/04/06 17:00:30 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class	Zombie
{
public:
	Zombie(std::string name = "Noname");
	~Zombie( void );
	void announce( void );
	void setName( std::string name );
private:
	std::string _name;
};

Zombie* zombieHorde( int N, std::string name );

#endif
