/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 18:07:38 by ccartman          #+#    #+#             */
/*   Updated: 2022/04/15 18:20:40 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
public:
	Dog(void);
	Dog(const Dog &other);
	~Dog(void);

	Dog &operator=(const Dog &other);

	void makeSound(void) const;
private:
	Brain *brain;
};

#endif
