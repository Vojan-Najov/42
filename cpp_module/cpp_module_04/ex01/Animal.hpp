/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 17:14:59 by ccartman          #+#    #+#             */
/*   Updated: 2022/04/15 19:21:26 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal
{
public:
	Animal(void);
	Animal(const std::string &type_);
	Animal(const Animal &other);
	virtual ~Animal(void);

	Animal &operator=(const Animal &other);

	const std::string &getType(void) const;
	virtual	void makeSound(void) const;

protected:
	std::string type;
};

#endif
