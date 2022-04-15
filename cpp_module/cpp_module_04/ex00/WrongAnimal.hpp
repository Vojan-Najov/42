/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 18:28:22 by ccartman          #+#    #+#             */
/*   Updated: 2022/04/15 19:23:06 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_ANIMAL_HPP
#define WRONG_ANIMAL_HPP

#include <string>

class WrongAnimal
{
public:
	WrongAnimal(void);
	WrongAnimal(const std::string &type_);
	WrongAnimal(const WrongAnimal &other);
	~WrongAnimal(void);

	WrongAnimal &operator=(const WrongAnimal &other);

	const std::string &getType(void) const;
	void makeSound(void) const;

protected:
	std::string type;
};

#endif
